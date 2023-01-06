package teach_03;

public class car {
	
	String brand = "";
	String fuel = "";
	static int wheel = 5;
	private String glass = "";
	
	public car(String brand, String fuel, String glass){
		this.brand = brand;
		this.fuel = fuel;
		this.glass = glass;
	}
	
	void plus(String fuel){
		if( !fuel.equals(this.fuel) ) {
			System.out.println("加错燃料了");
		}
		else {
			System.out.println("正在加"+fuel+"......");
		}
		
	}
	
	void setglass(String glass) {
		this.glass = glass;
	}
	
	public String getglass() {
		return glass;
	}
}
