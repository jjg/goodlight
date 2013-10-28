difference(){

	union(){
		cylinder(5,24,24);

		translate([10,-10,0]){
			cube([20,20,3]);
		}
	}

	translate([0,0,2]){
		difference(){
			cylinder(3,23,23);
			cylinder(5,15,15);
		}
	}

	cylinder(12,14,14);

	translate([25,-5,0]){
		cube([3,10,10]);
	}
}