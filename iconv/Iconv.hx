package iconv;

/**
 * ...
 * @author Scott Lee
 */
class Iconv
{
	static public inline var UTF8		= "utf-8";
	static public inline var GB2312		= "gb2312";
	static public inline var CP936		= "cp936";
	static public inline var GBK		= "gbk";

	static public function convert(str:String, fromType:String, toType:String):String
	{
		return _iconv_convert(str, fromType, toType);
	}
	
	static var _iconv_convert = iconv.Loader.load("iconv", "iconv_convert", 3);
}