#include <stdio.h>

int main(int argc, char* argv[])
{
	//���� ���� ���� 
	FILE* file;
	
	//���Ͽ� ���� � ������ ���� ���� �Ҵ�
	file = fopen("test.txt", "w");
	//  ���� ��� ^           ^ ���� ��� 
	//r : read; �б� 
	//w : write; ���� 
	//a : append; �߰� 
	//�� �ִµ� �������ϱ� �̰Ÿ� �Ƽ� 
	
	//w, a�� �ش� ��ο� ������ ������ ���� ����
	//r�� �ش� ��ο� ������ ������ null ��ȯ 
	
	//���� �̸��� �ƴϰ� �ݵ�� ��η� ��� ��!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/*
		C:\User\asdf\test.txt �̰� User�� exe ���α׷��� �ִ�  ��� 
		
		"test.txt" 			X
		"asdf\\test.txt" 	O
		
		�����ϴ� ������ ���� ��ġ�� �ִ� ��� ���� �̸��� �ᵵ �� 
	*/
	 
	
	//�Է� �ޱ� 
	char input[100];
	printf("�Է� : "); 
	scanf("%s", input);
	
	//�ؽ�Ʈ �߰� 
	fputc('a', file);                   //fputc : File PUT Character; ĳ���� ���� �߰� 
	fputs("\nasdf", file);	//fputs : File PUT String; ���ڿ� �߰� 
	fprintf(file, "\n%s", input);       //fprintf : printf�� �Ȱ��� 
	
	//���� �ݱ�
	//�� ������ ������ Ŀ���� ���� �� �־ ����� ���� �� ���� 
	fclose(file);
	
	//�б�� �ٽ� ���� 
	file = fopen("test.txt", "r");
	
	//��� ���� �Է� �ޱ�
	char output[100];
	fread(output, 1, 100, file);		//���� ��ü �б� 
	
	printf("\n%s", output); 
	
	fclose(file);
	file = fopen("test.txt", "r");
	
	char charoutput = fgetc(file); 		//fgetc : File GET Character; ĳ���� ���� �б�
	fgetc(file);	//�ٹٲ� ���� \n �о �� �ٲٱ�
	
	//feof : File End Of File; ������ ������ Ȯ��
	//�������̸� true�� ��ȯ
	while (!feof(file)){
		fgets(output, 100, file); 		//fgets : File GET String; ���ڿ� �б� 
		printf("\n%s", output);
	} 
	
	fclose(file);
	return 0;
}
