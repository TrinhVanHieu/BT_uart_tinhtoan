
#ifndef __HW_STM32F051R8_H__
#define __HW_STM32F051R8_H__


#define write_reg(addr, value)  *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)    *((unsigned long int *)(addr)) & (mask)

/* RCC - clock */
#define BASE_ADDR_RCC           0x40021000u
#define RCC_CR                  (BASE_ADDR_RCC + 0x00)
#define RCC_CFGR                (BASE_ADDR_RCC + 0x04)
#define RCC_CIR                 (BASE_ADDR_RCC + 0x08)
#define RCC_AHBENR              (BASE_ADDR_RCC + 0x14)
#define RCC_APB2ENR             (BASE_ADDR_RCC + 0x18)
#define RCC_CFGR2               (BASE_ADDR_RCC + 0x2C)
#define RCC_CFGR3               (BASE_ADDR_RCC + 0x30)
#define RCC_CR2                 (BASE_ADDR_RCC + 0x34)

/* GPIO */
#define BASE_ADDR_GPIOA         0x48000000u
#define BASE_ADDR_GPIOC         0x48000800u
#define GPIOC_MODER             (BASE_ADDR_GPIOC + 0x00u)
#define GPIOA_MODER             (BASE_ADDR_GPIOA + 0x00u)
#define GPIO_MODER_INPUT        0x00u
#define GPIO_MODER_OUTPUT       0x01u
#define GPIO_MODER_ALT          0x02u

#define GPIOC_BSRR              (BASE_ADDR_GPIOC + 0x18u)

#define GPIOA_IDR               (BASE_ADDR_GPIOA + 0x10u)
#define GPIOA_PUPDR             (BASE_ADDR_GPIOA + 0x0Cu)
#define GPIOA_AFRL              (BASE_ADDR_GPIOA + 0x20u)
#define GPIOA_AFRH              (BASE_ADDR_GPIOA + 0x24u)

#define AF0                     0x0
#define AF1                     0x1
#define AF2                     0x2
#define AF3                     0x3
#define AF4                     0x4
#define AF5                     0x5
#define AF6                     0x6
#define AF7                     0x7

/* Led LD3 - PC9 */
#define LD3_PIN                 9
#define LD4_PIN                 8

/* user button (B1) - PA0 */
#define USER_BUTTON             0

/* EXTI */
#define BASE_ADDR_EXTI          0x40010400u
#define EXTI_IMR                (BASE_ADDR_EXTI + 0x00u)
#define EXTI_RTSR               (BASE_ADDR_EXTI + 0x08u)
#define EXTI_PR                 (BASE_ADDR_EXTI + 0x14u)

/* SYSCFG */
#define BASE_ADDR_SYSCFG        0x40010000u
#define SYSCFG_EXTICR1          (BASE_ADDR_SYSCFG + 0x08u)

/* NVIC */
#define NVIC_ISER               0xE000E100u
#define NVIC_ICER               0xE000E180u
#define NVIC_ISPR               0xE000E200u
#define NVIC_ICPR               0xE000E280u
#define NVIC_PRI1               0xE000E404u
#define NVIC_PRI7               0xE000E418u

/* USART */
#define BASE_ADDR_USART1        0x40013800u

#define USART_CR1               (BASE_ADDR_USART1 + 0x00)
#define USART_CR2               (BASE_ADDR_USART1 + 0x04)
#define USART_CR3               (BASE_ADDR_USART1 + 0x08)
#define USART_BRR               (BASE_ADDR_USART1 + 0x0C)
#define USART_RQR               (BASE_ADDR_USART1 + 0x18)
#define USART_ISR               (BASE_ADDR_USART1 + 0x1C)
#define USART_ICR               (BASE_ADDR_USART1 + 0x20)
#define USART_RDR               (BASE_ADDR_USART1 + 0x24)
#define USART_TDR               (BASE_ADDR_USART1 + 0x28)

/* end file */
#endif /* __HW_STM32F051R8_H__ */

