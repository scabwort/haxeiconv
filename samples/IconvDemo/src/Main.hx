package ;

import cpp.Lib;
import iconv.Iconv;
import sys.FileSystem;
import sys.io.File;

/**
 * ...
 * @author Scott Lee
 */

class Main 
{
	
	static function main() 
	{		
		var src = "fdsaba中国";
		var dst = Iconv.convert(src, Iconv.UTF8, Iconv.GB2312);
		trace(src);
		trace(dst);
		//File.saveContent("aa.txt", dst);
		FileSystem.createDirectory(dst);
	}
	
}