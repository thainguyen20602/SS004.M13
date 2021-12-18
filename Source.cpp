#include "console.h"
#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;
#define DOT_RAN 254 // Hình ảnh của con rắn
//Có thể sử dụng vòng lặp sau để xem những hình ảnh có thể sử dụng để làm đốt rắn
/*for (int i = 0; i < 256; i++)
	cout <<i<<':' << char(i)<<endl;*/

#define MAX 3 // Khởi tạo rắn với 3 đốt khởi đầu
#define LEN 1 
#define XUONG 2
#define TRAI 3
#define PHAI 4
#define TUONG_TREN 2 //Giới hạn tường trên
#define TUONG_DUOI 30 //Giới hạn tường dưới
#define TUONG_TRAI 4 //Giới hạn tường trái
#define TUONG_PHAI 90 //Giới hạn tường phải
struct point
{
	int x;
	int y;
};

point ran[MAX];//Tạo rắn với 3 đốt
int Sodot = 3;

void Khoitao();
void Hienthi(point Dotcuoicu);
point Dichuyen(int&);
void batsukien(int&);
void Wall();
point Moi();
bool Gameover();
bool KTanmoi(point);
void Themdot();
int main()
{
	Khoitao();//Khởi tạo
	int huong = PHAI,diem=0;//Hướng ban đầu di chuyển qua phải và điểm là 0
	Wall();//Vẽ tường
	point moi = Moi(),Dotcuoicu;//Tạo mồi,đốt cuối cũ
	gotoXY(TUONG_PHAI + 3, TUONG_TREN);//Tọa độ viết chữ
	cout << "Player 1";
	gotoXY(TUONG_PHAI+3, TUONG_TREN+1);//Tọa độ viết chữ
	cout << "Diem: " << diem;
	int start = clock(),end;//Khởi tạo biến đếm thời gian
	while (true)//Game start
	{
		if (Gameover() == true)//Kiểm tra Game over
		{
			clrscr();
			cout << "Game over\nBan dat duoc "<<diem<<" diem\n";
			//In ra điểm và kết thúc trò chơi
			break;
		}
		batsukien(huong);//Cập nhật hướng di chuyển
		Dotcuoicu=Dichuyen(huong);
		Hienthi(Dotcuoicu);//Hiển thị rắn
		if (KTanmoi(moi) == true)//Kiểm tra ăn mồi
		{
			Themdot();//Thêm đốt vào rắn
			moi = Moi();//Tạo và cập nhật mồi mới
			diem++;//Tăng điểm
			gotoXY(TUONG_PHAI + 3, TUONG_TREN+1);//Tọa độ viết chữ
			cout << "Diem: " << diem;//Cập nhật lại điểm
		}
		end = clock();
		gotoXY(TUONG_PHAI + 3, TUONG_TREN+2);
		cout << "Time: "<<int((end-start)/1000)<<'s';//Thời gian game đã bắt đầu
		Sleep(200);//Thay đổi số bên trong sleep để rắn di chuyển nhanh hay chậm
	}
	return 0;
}
//Tạo rắn với 3 đốt
void Khoitao()
{
	ran[0].x = 20;
	ran[1].x = 19;
	ran[2].x = 18;
	ran[0].y = ran[1].y = ran[2].y = 15;
}
//Hiển thị rắn với tọa độ đã được lưu
void Hienthi(point Dotcuoicu)
{
	//In đốt rắn
	for (int i = 0; i < Sodot; i++)
	{
		gotoXY(ran[i].x, ran[i].y);
		cout << (char)DOT_RAN;
	}
	//Xóa đốt rắn cuối cũ
	gotoXY(Dotcuoicu.x, Dotcuoicu.y);
	cout <<" ";
}
// Điều khiển rắn
point Dichuyen(int &huong)
{
	point Dotcuoicu = ran[Sodot - 1];
	//Dịch qua phải 1 phần tử
	for (int i = Sodot - 1; i >= 1; i--)
		ran[i] = ran[i - 1];
	//Cập nhật đầu rắn
	switch (huong)
	{
	case LEN:
		ran[0].y--;
		break;
	case XUONG:
		ran[0].y++;
		break;
	case TRAI:
		ran[0].x--;
		break;
	case PHAI:
		ran[0].x++;
		break;
	}
	return Dotcuoicu;
}
//Cập nhật hướng đi của rắn rắn di chuyển theo phím mũi tên trên bàn phím hoặc w,s,a,d
void batsukien(int &huong)
{
	int key = inputKey();
	if (huong!=XUONG&&(key == KEY_UP||key=='w'||key=='W'))
		huong = LEN;
	else if (huong!=LEN&&(key == KEY_DOWN || key == 's' || key == 'S'))
		huong = XUONG;
	else if (huong != PHAI && (key == KEY_LEFT || key == 'a' || key == 'A'))
		huong = TRAI;
	else if (huong != TRAI && (key == KEY_RIGHT || key == 'd' || key == 'D'))
		huong = PHAI;
}
//Vẽ tường
void Wall()
{
	for (int i = TUONG_TREN; i < TUONG_DUOI; i++)
	{
		gotoXY(TUONG_PHAI, i);
		cout << (char)222;
	}
	for (int i = TUONG_TREN; i < TUONG_DUOI; i++)
	{
		gotoXY(TUONG_TRAI, i);
		cout << (char)221;
	}
	for (int i = TUONG_TRAI; i <= TUONG_PHAI ; i++)
	{
		gotoXY(i, TUONG_TREN);
		cout << (char)220;
	}
	for (int i = TUONG_TRAI; i <= TUONG_PHAI ; i++)
	{
		gotoXY(i, TUONG_DUOI);
		cout << (char)223;
	}
}
//Tạo mồi
point Moi()
{
	srand(time(NULL));
	int y = TUONG_TREN + rand() % (TUONG_DUOI - TUONG_TREN - 2) + 1;
	int x = TUONG_TRAI + rand() % (TUONG_PHAI - TUONG_TRAI - 2) + 1;
	gotoXY(x, y);
	cout << 'o';
	return point{ x,y };
}
//Kiểm tra xem người chơi có thua hay không
bool Gameover()
{
	if (ran[0].y == TUONG_TREN)
		return true;
	if (ran[0].y == TUONG_DUOI)
		return true;
	if (ran[0].x == TUONG_TRAI)
		return true;
	if (ran[0].x == TUONG_PHAI)
		return true;
	return false;
}
//Kiểm tra xem đã ăn mồi hay chưa
bool KTanmoi(point moi)
{
	if (moi.x == ran[0].x&&moi.y==ran[0].y)
		return true;
	return false;
}
//Tăng rắn thêm 1 đốt 
void Themdot()
{
	ran[Sodot] = ran[Sodot - 1];
	Sodot++;
}