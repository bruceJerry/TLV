#include <stdio.h>
#include "tlvparse.h"

/*
b8和b7两位标识tag所属类别. 这个可以暂时不用理. b6决定当前的TLV数据是一个单一的数据和复合结构的数据. 
复合的TLV是指value域里也包含一个或多个TLV, 类似嵌套的编码格式. b5~b1如果全为1，则说明这个tag下面还有一个子字节.占两个字节, 否则tag占一个字节.

Length域的编码比较简单,最多有四个字节, 如果第一个字节的最高位b8为0, b7~b1的值就是value域的长度. 
如果b8为1, b7~b1的值指示了下面有几个子字节. 下面子字节的值就是value域的长度.
0110 1111  0010 0010  6f 22
1000 0100  0000 1110  84 0e
1010 1001  0001 0000  a5 10
1000 1000  0000 0001  88 01
0101 1111  0010 1101 0000 0010 5f2d 02
*/
int main(void)
{
	unsigned char buf2[] = {
        0x6F,0x22,0x84,0x0E,0x31,0x50,0x41,0x59,0x2E,0x53,0x59,0x53,
        0x2E,0x44,0x44,0x46,0x30,0x31,0xA5,0x10,0x88,0x01,0x01,0x5F,
        0x2D,0x02,0x7A,0x68,0xBF,0x0C,0x05,0x9F,0x4D,0x02,0x0B,0x0A
	};

	unsigned char buf3[] = {
		0x70,0x1C,0x61,0x1A,0x4F,0x08,0xA0,0x00,0x00,0x03,0x33,0x01,
		0x01,0x02,0x50,0x0B,0x50,0x42,0x4F,0x43,0x20,0x43,0x52,0x45,
		0x44,0x49,0x54,0x87,0x01,0x01
	};


	//parse 1
	struct TLVNode* node = TLV_Parse(buf2, sizeof(buf2));
	TLV_Debug(node);

	//parse 2
	struct TLVNode* node2 = TLV_Parse(buf3, sizeof(buf3));
	TLV_Debug(node2);

	TLV_Merge(node, node2);
	TLV_Free(node2);

	struct TLVNode* found = TLV_Find(node, 0x9f4d);
	if (found) {
		printf("FOUND! 9f4d\n");
	} else {
		printf("NOT FOUND! 9f4d\n");
	}

	found = TLV_Find(node, 0x4f);
	if (found) {
		printf("FOUND! 4f\n");
	} else {
		printf("NOT FOUND! 4f\n");
	}
	return 0;
}
