#include <stdio.h>

//���ĺ� ������ŭ �迭 ����  
static int alphabets[26];
//�� �� ��Ÿ ���� 
static int anotherCharacter;
//�׳� �����ϸ� �Ҵ��� �� �Ǿ static �ٿ��� 

int main(int argc, char* argv[]){
	
	//���� �����ϴ� �뷡�� ���� 
	FILE* lyrics = fopen("You're Just Like Pop Music.txt", "r");
	
	while (!feof(lyrics)){
		char c[1] = { fgetc(lyrics) };
		strupr(c);		
		
		int ascii = c[0] - 65;
		
		if (ascii < 0 || ascii > 25){
			anotherCharacter++;
		}
		else{
			alphabets[ascii]++;
		}
	}
	
	
	int i;
	for (i = 0; i < 26; i++){
		printf("%c : %d\n", i + 65, alphabets[i]);
	}
	
	printf("Another characters : %d", anotherCharacter);
}
