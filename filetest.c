#include <stdio.h>

int main(int argc, char* argv[])
{
	//파일 변수 생성 
	FILE* file;
	
	//파일에 대해 어떤 동작을 할지 여부 할당
	file = fopen("test.txt", "w");
	//  파일 경로 ^           ^ 동작 방법 
	//r : read; 읽기 
	//w : write; 쓰기 
	//a : append; 추가 
	//더 있는데 귀찮으니까 이거만 아셈 
	
	//w, a는 해당 경로에 파일이 없으면 새로 생성
	//r은 해당 경로에 파일이 없으면 null 반환 
	
	//파일 이름이 아니고 반드시 경로로 써야 됨!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/*
		C:\User\asdf\test.txt 이고 User에 exe 프로그램이 있는  경우 
		
		"test.txt" 			X
		"asdf\\test.txt" 	O
		
		참조하는 파일이 같은 위치에 있는 경우 파일 이름만 써도 됨 
	*/
	 
	
	//입력 받기 
	char input[100];
	printf("입력 : "); 
	scanf("%s", input);
	
	//텍스트 추가 
	fputc('a', file);                   //fputc : File PUT Character; 캐릭터 문자 추가 
	fputs("\nasdf", file);	//fputs : File PUT String; 문자열 추가 
	fprintf(file, "\n%s", input);       //fprintf : printf랑 똑같음 
	
	//파일 닫기
	//안 닫으면 파일의 커서가 끝에 가 있어서 제대로 읽을 수 없음 
	fclose(file);
	
	//읽기로 다시 열기 
	file = fopen("test.txt", "r");
	
	//출력 문자 입력 받기
	char output[100];
	fread(output, 1, 100, file);		//파일 전체 읽기 
	
	printf("\n%s", output); 
	
	fclose(file);
	file = fopen("test.txt", "r");
	
	char charoutput = fgetc(file); 		//fgetc : File GET Character; 캐릭터 문자 읽기
	fgetc(file);	//줄바꿈 문자 \n 읽어서 줄 바꾸기
	
	//feof : File End Of File; 파일의 마지막 확인
	//마지막이면 true를 반환
	while (!feof(file)){
		fgets(output, 100, file); 		//fgets : File GET String; 문자열 읽기 
		printf("\n%s", output);
	} 
	
	fclose(file);
	return 0;
}
