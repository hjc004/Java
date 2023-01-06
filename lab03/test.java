package teach_03;

public class test {

	public static void main(String[] args) {

		car benchi = new car("benchi","qiyou","kangning");
		System.out.println("benchi's brand is "+benchi.brand);
		benchi.plus("qiyou");
		System.out.println("benchi's wheels is "+benchi.wheel);
		
		System.out.println("");  //
		
		car BYD = new car("BYD","electricity","wuming");
		System.out.println("BYD's brand is "+BYD.brand);
		BYD.plus("electricity");
		System.out.println("BYD's wheels is "+BYD.wheel);
		
		System.out.println("");  //
		
		benchi.wheel = 12;
		System.out.println("benchi's wheels change to "+benchi.wheel);
		System.out.println("BYD's wheels also change to "+BYD.wheel);
		
		System.out.println("");  //
		
		benchi.setglass("daxingxing");
		System.out.println(benchi.getglass());
	}

}
