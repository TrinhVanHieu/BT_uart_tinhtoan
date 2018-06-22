#include "project.h"


/*************************************************************************************************/

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

void Tong(int a, int b)
{
	int s = a + b;
	usart_send_string("\r\nTong 2 so vua nhap la: \t");
	usart_send_byte(s);
}

char a[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int m, n;
unsigned int j = 0;
int s = 0; 
void main(void)
{
	unsigned char tham_so = 0;
	unsigned char xx_tinh_toan = 0;
	unsigned int value = 0;
	unsigned int value_sh_1 = 0;
	unsigned int value_sh_2 = 0;
	unsigned int tong = 0;
	
    system_init();
    enabled_clock();
    pin_init();
    usart_init();

    interrupt_init();

    /* send "Hello world -MCU" to terminal app on PC */
	usart_send_string("\r\nNhap so thu nhat: ");
    led_on(LD4_PIN);
	
	while(1)
	{
		if (0 != rx_data)
		{
			if(0x0D != rx_data) // so
			{
				for (int i = 0; i < 10; i++)
				{
					if (rx_data == a[i])
					{
						m = i;
						break;
					}
				}
				value = value*10 + m;
				usart_send_byte(rx_data);
			}
			else // enter
			{
				if (0 == tham_so)
				{
					value_sh_1 = value;
					usart_send_string("\r\nNhap so thu hai: ");
					tham_so = 1;
				}
				else
				{
					value_sh_2 = value;
					usart_send_string("\r\nNhap so thu nhat: ");
					tham_so = 0;
					xx_tinh_toan = 1;
				}
				value = 0;
			}
			rx_data = 0;
		}
		if (xx_tinh_toan)
		{
			tong = value_sh_1 + value_sh_2;
			xx_tinh_toan = 0;
		}
	}
	usart_send_string("\r\nThoat thanh cong roi:");
}

