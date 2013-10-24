iconv
========

fork of iconv ( http://www.gnu.org/software/libiconv/ ) for Haxe 3/Neko 2

## 使用

最常见的场景在Windows的文件路径使用GB2312编码，和haxe内部的编码格式不同，创建文件时会乱码。

    var dst = Iconv.convert("中国 UTF-8", Iconv.UTF8, Iconv.GB2312);
    FileSystem.createDirectory(dst);

## 安装

    haxelib install haxeiconv

## 贡献

* [@scabwort](https://github.com/scabwort)
* [@imcj](https://github.com/imcj)

## 需求

    haxe >= 3.0
    neko >= 2.0

## License

[The LGPL License](https://github.com/scabwort/haxeiconv/blob/master/LICENSE)

### Status ###
The files are updated and are _mostly working_ for all platforms. I will try to maintain it the best I can, if any issues are reported.
