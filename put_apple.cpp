/*
题目描述
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
 
输入
每个用例包含二个整数M和N。0<=m<=10，1<=n<=10。<=n<=10<=m<=10
 
样例输入
7 3
 
样例输出
8
    
/**
     * 计算放苹果方法数目

     * 输入值非法时返回-1
     * 1 <= m,n <= 10<><= m,n <= 10<>
     * @param m 苹果数目
     * @param n 盘子数目数
     * @return 放置方法总数
     * 
     */
    public static int count(int m, int n)
 
 
 
知识点	循环
运行时间限制	10M
内存限制	128
输入	
输入两个int整数
输出	
输出结果，int型
样例输入	7 3
样例输出	8
*/

/*解题分析：
设f(m,n)为m个苹果，n为盘子的放法数目，则先对n作讨论，
当n>m：必定有n-m个盘子永远空着，去掉它们对摆放苹果方法数目不产生影响。即if(n>m) f(m,n) = f(m,m)　　
当n<=m：不同的放法可以分成两类：
1、有至少一个盘子空着，即相当于f(m,n) = f(m,n-1);  
2、所有盘子都有苹果，相当于可以从每个盘子中拿掉一个苹果，不影响不同放法的数目，即f(m,n) = f(m-n,n).
而总的放苹果的放法数目等于两者的和，即 f(m,n) =f(m,n-1)+f(m-n,n) 
递归出口条件说明：
当n=1时，所有苹果都必须放在一个盘子里，所以返回１；
当没有苹果可放时，定义为１种放法；
递归的两条路，第一条n会逐渐减少，终会到达出口n==1; 
第二条m会逐渐减少，因为n>m时，我们会return f(m,m)　所以终会到达出口m==0．
 */
#include <iostream>
using namespace std;

int f(int m,int n){
  //判断非法数据的情况
	if(m<0 || m>10 || n<0 || n>10)
		return -1;
	
	if(m==0 | n==1)
		return 1;
	
	if(m<n)
		return f(m,m);
	else
		return f(m,n-1)+f(m-n,n);
}

int main(){
	
	int m,n;
	cin>>m;
	cin>>n;
	cout<<f(m,n);

	system("pause");
	return 0;


}
