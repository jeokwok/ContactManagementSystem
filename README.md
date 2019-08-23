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
## 支持
1.项目还会持续更新。

2.项目仅用于学习和交流，严禁用于任何商业用途。

3.水平有限，如果有什么问题可以留言或是qq联系，370156664

4.感觉有帮助，支持下作者，欢迎点赞和star

