# hello-world
Just another repository

hello-world  java 

learn java 

byte short int long   char float double boolean 

import  java.util.Arrays;

public class Demo{
	int[] array = {};
	int count =  0;                                        //计数器 计算冒泡的次数
	for(int j = 0; j < array.length - 1 ; j++){            //array.length - 1  每次冒泡一个最小数组值后 数组元素5位 只是需要排序4次
		boolean flag = false;                                //标识触发器，默认false状态，主要是防止已经有排序数组，避免重复操作，
                           					                     //每次冒泡前，进行重置，在第一层循环中判断，如果没进行排序
						                                             //证明是有顺序直接跳出
		for(int i = 0; i < array.length- 1 - j ; i++)        // array.length - 1 主要是防止数组访问越界  
		{                if（array[i] < array[i+1]）
			{                                                  //array.length - 1 - j  在每次冒泡完后，为避免和前面的再次进行比较 
			          int temp = array[i];                     //                      故减已经冒泡的次数
			          array[i] = array[i+1];
			          array[i+1] = temp;
			          flag = true;
			}
			count++;
		}
		if(!flag){
		      break;
		}
	}
	System.out.println(Arrays.toString(array));
	System.out.println(count);
}

class  AI{
	public static void main （String[] args）{
		Scanner sc = new Scanner(System.in);
		String str;
		while(true){
			str = sc.next();	
			str = str.replace(target: "吗", replacement：“haode  ”);
	
			System.out.println(str);
			}
	}
         }

class wordSet{    }



class word{
                String strIn;
	String strOut;   
                word(){}
	public String checkWord(String s1, String s2, boolean status, int flag)
	   {
	
                void showResult( String  result){
		System.out.println(result);
                }
		
intetface C{
    public void showNumber();
  
}
可以不可以模仿人类大脑的这个特点，构造多层的神经网络，较低层的识别初级的图像特征，若干底层特征组成更上一层特征，最终通过多个层级的组合，最终在顶层做出分类呢？答案是肯定的，这也是许多深度学习算法的灵感来源，也包括卷积神经网络（CNN）算法。

## 支持
1.项目还会持续更新。

2.项目仅用于学习和交流，严禁用于任何商业用途。

3.水平有限，如果有什么问题可以留言或是qq联系，370156664

4.感觉有帮助，支持下作者，欢迎点赞和star

