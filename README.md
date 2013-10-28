iconv
========

fork of iconv ( https://github.com/scabwort/haxeiconv ) for Haxe 3/Neko 2

## how to use

Many system use native code, like windows, if you want keep coding with haxe coding, you maybe need change the native coding to haxe coding(utf-8) to keep coding readable.
This library provides an Iconv.convert() implementation, for use on systems which don't have one, or whose implementation cannot convert from/to another coding.

eg. (if you are windows system of GBK, you can change coding to create readable folder using native coding.)
    
	var dst = Iconv.convert("中国 UTF-8", Iconv.UTF8, Iconv.GBK);
    FileSystem.createDirectory(dst);

## install

    haxelib install iconv

## contributor

* [@scabwort](https://github.com/scabwort)
* [@imcj](https://github.com/imcj)

## required

    haxe >= 3.0
    neko >= 2.0

## License

[The LGPL License](https://github.com/scabwort/haxeiconv/blob/master/LICENSE)

### Status ###
The files are updated and are _mostly working_ for all platforms. I will try to maintain it the best I can, if any issues are reported.
