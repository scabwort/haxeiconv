#ifndef STATIC_LINK
	#define IMPLEMENT_API
#endif
#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif
#include <hx/CFFI.h>

#include <stdio.h>
#include <stdlib.h>
#include <iconv.h>

char *Val2Str(value inVal)
{
   if (val_is_string(inVal))
      return  (char *)val_string(inVal);
   if (val_is_object(inVal))
   {
      value __s = val_field(inVal, val_id("__s"));
      if (val_is_string(__s))
         return  (char *)val_string(__s);
   }
   else if (val_is_object(inVal))
      return val_bool(inVal) ? (char *)"true":(char *)"false";
   return (char *)"";
}

int code_convert(char *from_charset,char *to_charset, const char *inbuf,size_t inlen,char *outbuf,size_t outlen)
{
	iconv_t cd;
	int rc;
	const char **pin = &inbuf;
	char **pout = &outbuf;

	cd = iconv_open(to_charset, from_charset);
	if (cd==0) return -1;
	memset(outbuf,0,outlen);
	if (iconv(cd, pin, &inlen, pout, &outlen)==-1) return -1;
	iconv_close(cd);
	
	return 0;
}

value iconv_convert(value inbufVal, value from_charsetVal, value to_charsetVal)
{
	char *from_charset;
	char *to_charset;
	char *inbuf;
	char *outbuf;
	size_t inlen;
	size_t outlen;
	
	from_charset = Val2Str(from_charsetVal);
	to_charset = Val2Str(to_charsetVal);
	inbuf = Val2Str(inbufVal);
	
	inlen = strlen(inbuf);
	outlen = inlen * 4;
	outbuf = (char *)malloc(outlen);
	
	if(code_convert(from_charset,to_charset,inbuf,inlen,outbuf,outlen) == -1)
		return val_null;
	
	inlen = strlen(outbuf);
	char *outData = (char *)malloc(inlen + 1);
	memcpy(outData, outbuf, inlen);
	*(outData + inlen) = 0;
	free(outbuf);
	
	value out = alloc_string(outData);
	return out;
}

DEFINE_PRIM(iconv_convert, 3);