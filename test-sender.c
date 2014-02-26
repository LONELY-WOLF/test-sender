#include <stdint.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int uart2 = open("/dev/ttyUSB0", O_RDWR);
	uint8_t buffer[16];
	//uint32_t* pSign = (uint32_t*)buffer;
	int16_t* pX = (int16_t *)(buffer + 4);
	int16_t* pY = (int16_t *)(buffer + 6);
	int16_t* pZ = (int16_t *)(buffer + 8);
	//*pSign = 0x7F7F7F7F;
	buffer[0] = 0x1F;
	buffer[1] = 0x1F;
	buffer[2] = 0x1F;
	buffer[3] = 0x1F;
	*pX = 102;
	*pY = -103;
	*pZ = 271;
	write(uart2, buffer, 10);
	return 0;
}
