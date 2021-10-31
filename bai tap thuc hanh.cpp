#include<stdio.h>

struct PhanSo {
	int tu;
	int mau;
};

struct PhanSo nhap(){
	struct PhanSo p;
		printf("nhap tu so: ");
	scanf("%d",&p.tu);

	while(1){

		printf("nhap mau so khac 0 :");
	scanf("%d",&p.mau);
	if (p.mau != 0) {
		break;
	}
	}
	return p;
}
	int ucln(int a,int b) {
		if (a<0) {
			a = a*-1;
		}
		if(b<0) {
			b=b*-1;
		}
		while (a!=b){
		if (a>b){
			a-=b;
		}
		else {
			b-=a;
		}
	}
	return a;
}
	
	struct PhanSo RutGon(struct PhanSo p) {
	if(p.tu != 0) {
		int u=ucln(p.tu,p.mau) ;
		p.tu /= u;
		p.mau /= u;
	}
	return p;
	}
	
	int bcnn (int a,int b){
	int u =ucln(a,b);
	return a*b / u;
    } 
    
	struct PhanSo cong (struct PhanSo a, struct PhanSo b) {
	struct PhanSo tong;
	tong.mau=bcnn( a.mau , b.mau);
	tong.tu = tong.mau / a.mau * a.tu + b.tu*tong.mau/b.mau;
	tong=RutGon(tong);
	return tong;
	}
struct PhanSo nhan (struct PhanSo a , struct PhanSo b) {
	struct PhanSo kq;
   
    kq.tu=a.tu*b.tu;
     kq.mau=a.mau*b.mau;
   kq=RutGon(kq);
    return kq;	
}
struct PhanSo chia (struct PhanSo a , struct PhanSo b) {
	struct PhanSo kq;
   
    kq.tu=a.tu*b.mau;
     kq.mau=a.mau*b.tu;
   kq=RutGon(kq);
    return kq;	
}
void hienThi(struct PhanSo p) {
	printf("%d/%d   ",p.tu,p.mau);
}
int main() {
	
int LuaChon;
do{
 printf("\n=======MENU======= \n1 nhap hai phan so : \n2Rut gon phan so: \n3Tong hai phan so: \n4Tich hai phan so: \n5Thuong hai phan so:\n0Thoat\nBan chon:");
 scanf("%d",&LuaChon);
 struct PhanSo a,b,tong,tich,thuong;
 switch(LuaChon) {
 	case 0 :break;
 	case 1: 
 		printf("nhap so thu nhat:\n");
 		a=nhap();
 		printf("nhap so thu hai:\n");
 		b=nhap();
 		printf("nhap phan so vua nhap:\n");
 		hienThi(a);
 		hienThi(b);
		break;
	case 2 :
		a=RutGon(a);
		b=RutGon(b);
		printf("\nphan so a sau khi rut gon :");
		hienThi(a);
		printf("\nphan so b sau khi rut gon :");
		hienThi(b);
		break;
	case 3: 
		tong=cong(a,b);
		printf("%d/%d+%d/%d=%d/%d\n",a.tu,a.mau,b.tu,b.mau,tong.tu,tong.mau);
		break;
	
	case 4:
		tich=nhan(a,b);
		printf("%d/%d * %d/%d=%d/%d\n",a.tu,a.mau,b.tu,b.mau,tich.tu,tich.mau);
		break;
	
	case 5:
		thuong=chia(a,b);
		printf("%d/%d / %d/%d=%d/%d\n",a.tu,a.mau,b.tu,b.mau,thuong.tu,thuong.mau);
		break;
	
}
	}
	while (LuaChon != 0);
	 
 
 
//	struct PhanSo p= nhap();
//	p= RutGon(p);
//		printf("%d/%d",p.tu,p.mau);
//	return 0;
   struct PhanSo p =nhap();
   struct PhanSo q =nhap();
 struct PhanSo kq =cong(p,q);
 //struct PhanSo tich=nhan(p,q);
//  struct PhanSo thuong=chia(p,q);
  
 //  printf("%d/%d+%d/%d=%d/%d\n",p.tu,p.mau,q.tu,q.mau,kq.tu,kq.mau);
//   printf("%d/%d * %d/%d=%d/%d\n",p.tu,p.mau,q.tu,q.mau,tich.tu,tich.mau);
 //   printf("%d/%d / %d/%d=%d/%d\n",p.tu,p.mau,q.tu,q.mau,thuong.tu,thuong.mau);
   return 0;
}
   
   

