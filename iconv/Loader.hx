package iconv;
#if cpp
import cpp.Lib;
#elseif neko
import neko.Lib;
#end

class Loader
{
	public static function load(lib:String, s:String, n:Int):Dynamic
	{
		return Lib.load(lib,s,n);
	}
}
