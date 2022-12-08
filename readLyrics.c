#include <stdio.h>

//알파벳 개수만큼 배열 생성  
static int alphabets[26];
//그 외 기타 문자 
static int anotherCharacter;
//그냥 선언하면 할당이 안 되어서 static 붙여줌 

int main(int argc, char* argv[]){
	
	//내가 좋아하는 노래임 ㅎㅎ 
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
