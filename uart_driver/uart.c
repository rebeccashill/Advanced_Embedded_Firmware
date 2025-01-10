void USART2_Init (void) {
// 1 Enable clock to access uart
    RCC->APB1ENR |= 0x20000;
// 2 Enable clock access to portA
    RCC->AHB1ENR = 0x01;
// 3 Enable pins for alternate function, pa2, pa3
    GPIOA->MODER &=~0x00F0;
    GPIOA->MODER |= 0x00A0;
// 4 Configure
    GPIOA->AFR[0] &= ~0xFF00;
    GPIOA->AFR[0] |= 0x7700;
//Configure uart

    USART2->BRR = 0x0683;
    USART2->CR1 = 0x000C; /*Enabled tx rx, 8-bit data*/
    USART2->CR2 = 0x000;
    USART2->CR3 = 0x000;
    USART2->CR1 = 0x2000; /*Enable uart*/
}

int USART2_write(int ch){

    while(! (USART2->SR & 0x0080)){}
    USART2->DR = (ch & 0xFF);

    return ch;
}

int USART2_read(void) {
    while(! (USART2->SR & 0x0020)){}
        return USART2->DR
}

struct __FILE { int handle; };
FILE __stdin = {0};
FILE __stdout = {1};
FILE __stdrerr = {2};

int fgetc(FILE *f){
    int c;
    c - USART2_read();

    if (c == '\r') {
        USART2_write(c);
        c = '\n';
    }

    USART2_write(c);

    return c;
}

/* Called by C library console/file output */
int fputc(int c, FILE *f){
    return USART2_write(c); /* Write the character to console */
}

int n;
char str[80];

void test_setup(void) {
    printf("Please enter a number: ");
    scanf("%d", &n);
    printf("The number entered is: %d\r\n", n);
    printf("Please type a character string: ");
    gets(str);
    printf("The character string entered is ");
    puts(str);
    printf("\r\n");
}