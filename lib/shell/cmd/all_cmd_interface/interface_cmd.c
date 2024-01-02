#include "interface_cmd.h"
#include "stdio.h"


extern void jump_app(uint32_t base_address);

//软件复位
int interface_reboot(int argc, char **argv)
{
   NVIC_SystemReset();     // 复位
	 return 0;
}


//跳转函数
int interface_go(int argc, char **argv)
{
		printf(" go go go \r\n");
//	jump_app(0x20000000);

	
   
	 return 0;
}


//ram操作
int interface_ram(int argc, char **argv)
{
   
	 return 0;
}


//硬件crc32
int interface_hardware_crc32( void * StartAddress, uint32_t size)
{
//   size_t hard_crc32Result = HAL_CRC_Calculate(&hcrc,( void *)StartAddress,size);
//   hard_crc32Result ^= 0xffffffffU;
//	 return hard_crc32Result;
	return 0;
}






unsigned int str2hex(const char* s)
{
	unsigned int sum=0;
    unsigned char c;
    unsigned int val;
	while ( *s == ' '  ||  *s == '\t') s++;

    if (*s == '0')s++;
    if (*s == 'x')s++;
    if (*s == 'X')s++;    

    c = *s;
	while (c)
	{
        if (c >= '0' && c <= '9')
            val = c - '0';
        else if (c >= 'a' && c <= 'z')
            val = c - 'a' + 10;
        else if (c >= 'A' && c <= 'Z')
            val = c - 'A' + 10;
		sum = sum * 16 + val;
		++s;
        c = *s;
	}
	return sum;
}



