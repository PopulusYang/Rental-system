# 东北大学计算机C语言课设
- 租房管理
- 仅供参考
# 项目说明

## 目录
- [项目概述](#项目概述)
- [项目结构](#项目结构)
- [主要文件](#主要文件)
- [许可证](#许可证)
- [注意事项](#注意事项)

## 项目概述
本项目是一个租赁系统，包含多个模块如公寓、机构、客户和预约等。

## 项目结构
- `admin.bin`
- `agency.bin`
- `appointment.bin`
- `class_design.c`
- `Class_design.vcxproj`
- `Class_design.vcxproj.filters`
- `color.c`
- `customer.bin`
- `filecach.c`
- `flat.bin`
- `information_search.c`
- `list.h`
- `listwriting.c`
- `log.c`
- `log.txt`
- `others.c`
- `output.c`
- `sort.c`
- `temphead.h`
## 主要文件
### class_design.c
这是项目的主文件，包含了程序的入口点 `main` 函数。在这个文件中，定义了管理员 (`Admin`) 和代理 (`Agency`) 的链表结构，并进行了初始化。

### list.h
这个头文件包含了链表操作的相关定义。

### temphead.h
这个头文件包含了项目中使用的一些基本定义和宏。

## 注意事项
- 项目中使用了 `_CRT_SECURE_NO_WARNINGS` 宏，以避免某些安全警告。
- 项目中使用了 `logError` 函数，但未在代码中定义，需要在 `log.c` 或其他相关文件中实现。

## 许可证
此项目使用MIT许可证，详情见[LICENSE](LICENSE)文件。
