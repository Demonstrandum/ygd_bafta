function Player(name, x, y, xl, yl, c) {
	this.name = name;
	this.grav = 0;
	this.canjump = true;

	this.x = x;
	this.y = y;
	this.xl = xl;
	this.yl = yl;

	//Custom Colour
	this.c = c;

	this.render = function() {
		fill(this.c[0], this.c[1], this.c[2]);
		stroke(this.c[0], this.c[1], this.c[2]);

		rect(this.x, this.y, this.xl, this.yl);

		if (players[activePlayer].name == this.name) {
			fill(255);
			stroke(255);
			//Show Active Player
			triangle(this.x + (this.xl / 2) - 5, this.y - 10,
				this.x + (this.xl / 2) + 5, this.y - 10, this.x + (this.xl / 2), this.y - 5,)
		}
	}

	this.move = function(d) {
		this.x += d[0];
		this.y += d[1] + this.grav;
	}

	this.collision = function(array) {
		for (var i = 0; i < array.length; i++) {
			if (array[i].name != this.name) {
				if ((this.x >= array[i].x && this.x <= array[i].x + array[i].xl) ||
					(this.x + this.xl >= array[i].x && this.x + this.xl <= array[i].x + array[i].xl)) {
					if ((this.y >= array[i].y && this.y <= array[i].y + array[i].yl) ||
						(this.y + this.yl >= array[i].y && this.y + this.yl <= array[i].y + array[i].yl)) {
						players[activePlayer].x += 0.5 * dir[0];
						players[activePlayer].y += 2 * dir[1];

						dir[1] = 0;
						this.canjump = true;
						this.grav = (this.grav * -1) / 2;
					}
				}
			}
		}
	}

	this.gravity = function() {
		if (players[activePlayer].name == this.name) {
			this.grav += 0.1;
		}
		else {
			this.grav = 0;
		}
	}
}
