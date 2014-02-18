#include <stdint.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int uart2 = open("/dev/ttyUSB0", O_RDWR);
	uint8_t buffer[16];
	uint32_t* pSign = (uint32_t*)buffer;
	float* pX = (float*)(buffer + 4);
	float* pY = (float*)(buffer + 8);
	float* pZ = (float*)(buffer + 12);
	*pSign = 0xFEFEFEFE;
	*pX = 0.1;
	*pY = 0.2;
	*pZ = 0.3;
	write(uart2, buffer, 16);
	return 0;
}
