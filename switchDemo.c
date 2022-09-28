/*  
	版本：1.1 修复后面开关误触导致的停止问题（未验证）
	
*/
#include <stdio.h>
#include <stdint.h>

uint8_t Head = 0;
uint8_t Tail = 0;
typedef struct {
	uint8_t firstTrigger;
	uint8_t secondTrigger;
	uint8_t key;
	uint8_t keyflag;
}key_t;
key_t key1;
int num = 1;
int getFindSolu(uint8_t *Head, uint8_t *Tail,key_t *key1) {
	if(*Head == 1) {
		key1 -> firstTrigger = 1;//记录第一个开关的状态
	} 
	if(*Tail == 1) {
		key1 -> secondTrigger = 1;//记录第二个开关的状态
	}
	/* 将两个光电开关的状态抽象成一个开关状态 */ 
	if((*Head == 0 && *Tail == 0) && (key1 -> firstTrigger == 1) && (key1 -> secondTrigger == 1) ) { //两开关都没有被遮挡且没有经历过障碍
		key1->keyflag = 1;///* 对已经通过后的状态进行记录 */记录为已经经过
	}
	/*对抽象过的开关状态进行扫描 */
	if(key1->keyflag == 1) {//如果已经经过而且抽象开关再次关闭，停止向前
		printf("Stop!\n");
		key1 -> key = 0;
		key1 -> keyflag = 1;
		return 1;//切换到下一状态
	}
	if(key1->keyflag == 0) {
		printf("go on\n");
		return 0;
	} 
}
void updateStaus(key_t *key) {
	key -> firstTrigger = 0;
	key -> secondTrigger = 0;
	key -> keyflag = 0;
}
int main(void) {
	key1.key = 0;
	key1.keyflag = 0;
	/* 更新光电开关的状态 */
	while(1) {
			printf("Switch State:\n");
			printf("Head:\n");
			scanf("%d" ,&Head);
			printf("Tail:\n");
			scanf("%d" ,&Tail);
			getFindSolu(&Head, &Tail, &key1);
	}
	return 0;
}