package Homework_01_01;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class ZY01 {

	public static void main(String[] args) {
		//返回当前日期
		Pub_fun calendar_01 = new Pub_fun();
		System.out.println(calendar_01.year + "/" + (calendar_01.month+1) + "/" + (calendar_01.date)); 
		
		//返回当前日期和时间
		Pub_fun calendar_02 = new Pub_fun();
		System.out.println(calendar_02.year + "/" + (calendar_02.month+1) + "/" + (calendar_02.date) + " " + (calendar_02.hour+12) + ":" + calendar_02.minute + ":" + calendar_02.second); 
		
		//返回当前之后1天的日期和时间
		Pub_fun calendar_03 = new Pub_fun();
		System.out.println(calendar_03.year + "/" + (calendar_03.month+1) + "/" + (calendar_03.date+1) + " " + (calendar_03.hour+12) + ":" + calendar_03.minute + ":" + calendar_03.second); 
		
		//返回当前之后1天的日期和时间
		Pub_fun calendar_04 = new Pub_fun();
		System.out.println(calendar_04.year + "/" + (calendar_04.month+1) + "/" + (calendar_04.date-1) + " " + (calendar_04.hour+12) + ":" + calendar_04.minute + ":" + calendar_04.second); 
		
	}

}
