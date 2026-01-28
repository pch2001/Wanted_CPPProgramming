#include <iostream>

int main() 
{
	FILE* file = nullptr;
	fopen_s(&file, "Test.txt", "rt");

	//파일 읽기 실패
	if (file == nullptr) 
	{
		std::cout << "Failed to read file.\n";
		__debugbreak();
		
	}

	fseek(file, 0, SEEK_END);
	size_t fileSize = ftell(file);
	std::cout << "FileSize : " << fileSize << "\n";

	// ! 파일 크기 가늠한 뒤에 다시 처음부터 읽으려면 FP 되돌려야함
	fseek(file, 0, SEEK_SET);

	//블록 단위로 읽기
	// 읽은 데이터를 저장하기 위한 공간(버퍼) 필요
	char buffer[1024] = { };
	size_t readSize = fread(buffer, sizeof(char), 1024, file);
	std::cout << "readSize " << readSize << "\n";
	std::cout << buffer;
	//파일 쓰기
	//const char* message = "프로그램에서 작성한 문자열 값입니다.";
	//fputs(message, file);


	//파일 읽기
	/*char data[256] = { };
	while (true) {
		if (fgets(data, 256, file) == nullptr)
		{
			break;
		}
		std::cout << data;
	}*/
	fclose(file);
}