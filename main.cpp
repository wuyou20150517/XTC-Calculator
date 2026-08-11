/*
 * v1.1.0
 * 
 * Copyright (c) 2026 wuyou. All rights reserved.
 * 
 * Implementation based on GitHub project: XTCADBCode-Web
 * 实现逻辑基于 GitHub 开源项目：XTCADBCode-Web
 * https://github.com/OnesoftQwQ/XTCADBCode-Web
 * 
 * Core algorithm functions (Hy3) & helper functions: Hy3 (AI-assisted)
 * 核心算法与辅助函数：Hy3（AI 辅助）
 * 
 * main() & flash(): wuyou
 * 主程序与界面：wuyou
 */
#include<iostream>
#include<string>
#include<cstdio>
#include<termios.h>
#include<unistd.h>
using namespace std;

string input,output1,output2,wy;

int jsXor(int a, int b) { return (int32_t)a ^ (int32_t)b; }

string pad2(int x) {
    char b[16];
    snprintf(b, sizeof(b), "%02d", x);
    return b;
}

string v1(const string& code, int mode) {
	if (mode == 2) {
		int i1 = stoi(code.substr(0, 2));
		int i2 = stoi(code.substr(2, 2));
		int i3 = stoi(code.substr(4, 2));
		int i4 = stoi(code.substr(6, 2));
		int i5 = stoi(code.substr(8, 2));
		int i6 = jsXor(i5, (i3 + i4));
		int i7 = jsXor(i4, i6);
		int i8 = jsXor(i3, i6);
		int i9 = jsXor(i1, i6);
		int i10 = jsXor(i2, i6);
		string r1 = pad2(i9) + pad2(i10) + pad2(i8) + pad2(i7) + pad2(i6);
		int a2 = stoi(r1.substr(0, 2));
		int b2 = stoi(r1.substr(2, 2));
		int c2 = stoi(r1.substr(4, 2));
		int d2 = stoi(r1.substr(6, 2));
		int e2 = stoi(r1.substr(8, 2));
		int f2 = jsXor(d2, c2);
		int g2 = jsXor(e2, c2);
		int h2 = jsXor(c2, (f2 + g2));
		int i2_2 = jsXor(a2, g2);
		int j2 = jsXor(b2, g2);
		return pad2(i2_2) + pad2(j2) + pad2(f2) + pad2(g2) + pad2(h2);
	} else {
		int i1 = stoi(code.substr(0, 2));
		int i2 = stoi(code.substr(2, 2));
		int i3 = stoi(code.substr(4, 2));
		int i4 = stoi(code.substr(6, 2));
		int i5 = stoi(code.substr(8, 2));
		int i6 = jsXor(i5, (i3 + i4));
		int i7 = jsXor(i1, i6);
		int i4b = jsXor(i2, i6);
		string r1 = pad2(i7) + pad2(i4b) + pad2(i6);
		int a2 = stoi(r1.substr(0, 2));
		int b2 = stoi(r1.substr(2, 2));
		int c2 = stoi(r1.substr(4, 2));
		int e2 = jsXor(b2, a2);
		int f2 = jsXor(c2, a2);
		int d2 = jsXor(a2, (e2 + f2));
		return pad2(e2) + pad2(f2) + pad2(d2);
	}
}

string v2(const string& code, int mode) {
	int num = (mode == 2) ? 2 : 1;
	int key = (code[7] - '0') ^ num;
	if (key < 0 || key >= 7) return "";
	int v7 = (((code[key] - '0') - key) % 10 + 10) % 10;
	string r1 = "";
	for (int i = 0; i < 7; i++) {
		if (i == key) r1 += to_string(v7);
		else r1 += to_string(((code[i] - '0') - v7 + 10) % 10);
	}
	for (int attempt = 0; attempt < 200; attempt++) {
		int keyId = rand() % 7;
		int keyValue = r1[keyId] - '0';
		string result = "";
		for (int i = 0; i < 7; i++) {
			int ck = (i == keyId) ? keyId : keyValue;
			result += to_string(((r1[i] - '0') + ck) % 10);
		}
		result += to_string(num ^ keyId);
		if (result != "" && result != code) return result;
	}
	return "";
}

int LorR(){
    struct termios o,r;
    tcgetattr(0,&o);
    r=o;
    r.c_lflag&=~(ICANON|ECHO);
    tcsetattr(0,TCSANOW,&r);
    char c[3];
    read(0,c,3);
    tcsetattr(0,TCSANOW,&o);
    return c[0]==27&&c[1]==91?(c[2]==68?-1:c[2]==67?1:0):0;
}

void c(const char*s,const char*m){printf("\033[%sm%s\033[0m",s,m);}

void cls(){printf("\033[2J\033[H");}

void flash(int chose){
    printf("\033[2J\033[H");
    c("1;32","      欢迎使用");c("1;94","【小天才计算器】\n");
    c("90","根据GitHub项目 XTCADBCode-Web 实现\n");
    c("33","------------------------------------\n输入校验码 > ");
    cout<<input<<flush;
    c("33","\n--------------计算成功--------------\n");
    if(chose==1){
        c("33","         [AOB]        自检\n          >> ");
        cout<<flush<<output1<<flush;
        c("33"," <<");
        fflush(stdout);
    }
    if(chose==2){
        c("33","          AOB        [自检]\n          >> ");
        cout<<flush<<output2<<flush;
        c("33"," <<");
        fflush(stdout);
    }
}

int main(){
    printf("\033[2J\033[H");
    c("1;32","      欢迎使用");c("1;94","【小天才计算器】\n");
    c("90","根据GitHub项目 XTCADBCode-Web 实现\n");
    c("33","------------------------------------\n输入校验码 > ");
    cin>>input;
    int len=input.size();
    if(len==10){
        output1=v1(input,1);
        output2=v1(input,2);
    }else if(len==8){
        output1=v2(input,1);
        output2=v2(input,2);
    }else{
        c("33","--------------输入错误--------------\n");
        c("31","错误：设备可能使用v3校验码，暂不支持");
        c("33","\n--------------谢谢使用--------------\n\n");
        c("90","   Most functions: Hy3\n   main() & flash(): wuyou\n   GitHub: XTCADBCode-Web\n   Copyright©️ 2026 wuyou.\n   All rights reserved.\n\n");
        return 0;
    }
    c("33","------------------------------------\n");
    c("33","计算中：");
    for(int a=0;a<28;a++){
        c("33","#");
        fflush(stdout);
        usleep(20000);
    }
    if(output1==""||output2==""){
        c("33","\n--------------计算失败--------------\n");
        c("31","计算时错误：校验码格式有误\n");
        c("33","--------------谢谢使用--------------\n\n");
        c("90","   Most functions: Hy3\n   main() & flash(): wuyou\n   GitHub: XTCADBCode-Web\n   Copyright©️ 2026 wuyou.\n   All rights reserved.\n\n");
        return 0;
    }
    int now=1,lr;
    while(1){
        flash(now);
        lr=LorR();
        if(lr==1)now=2;
        if(lr==-1)now=1;
        if(lr==0)break;
    }
    c("33","\n--------------谢谢使用--------------\n\n");
    c("90","   Most functions: Hy3\n   main() & flash(): wuyou\n   GitHub: XTCADBCode-Web\n   Copyright©️ 2026 wuyou.\n   All rights reserved.\n\n");
    return 0;
}
