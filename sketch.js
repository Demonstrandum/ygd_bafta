var players = [];
var platforms = [];

var activePlayer = 0;
var dir = [0, 0];

function setup() {
	createCanvas(600, 400);

	//Cube Player
	Cube = new Player('Cube', 0, 0, 10, 10, [255, 0, 100]);
	players.push(Cube);

	//Rect Player
	Rectangle = new Player('Rectangle', 20, 0, 10, 20, [200, 200, 0]);
	players.push(Rectangle);

	//Big Cube Player
	BigCube = new Player('BigCube', 40, 0, 40, 40, [0, 0, 255]);
	players.push(BigCube);

	//Flat Rectangle Player
	FlatRectagle = new Player('FlatRectagle', 0, 50, 80, 10, [0, 200, 100]);
	players.push(FlatRectagle);
}

function draw() {
	background(0);

	//Move Active Player
	players[activePlayer].move(dir);

	//Render Players
	for (var i = 0; i < players.length; i++) {
		players[i].collision(players);
		players[i].render();
	}

	//Render Platforms
	for (var i = 0; i < platforms.length; i++) {
		platforms[i].render();
	}
}

function Player(name, x, y, xl, yl, c) {
	this.name = name;

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
			triangle(this.x + (this.xl / 2) - 5, this.y - 10, this.x + (this.xl / 2) + 5, this.y - 10, this.x + (this.xl / 2), this.y - 5,)
		}
	}

	this.move = function(d) {
		this.x += d[0];
		this.y += d[1];
	}

	this.collision = function(array) {
		for (var i = 0; i < array.length; i++) {
			if (array[i].name != this.name) {
				if ((this.x >= array[i].x && this.x <= array[i].x + array[i].xl) || 
					(this.x + this.xl >= array[i].x && this.x + this.xl <= array[i].x + array[i].xl)) {
					if ((this.y >= array[i].y && this.y <= array[i].y + array[i].yl) || 
						(this.y + this.yl >= array[i].y && this.y + this.yl <= array[i].y + array[i].yl)) {
						players[activePlayer].x -= dir[0];
						players[activePlayer].y -= dir[1];
						dir = [0, 0];
					}
				}
			}
		}
	}
}

function keyPressed() {
	if (keyCode == RIGHT_ARROW)
		dir = [1, 0];
	else if (keyCode == LEFT_ARROW)
		dir = [-1, 0];
	else if (keyCode == UP_ARROW)
		dir = [0, -1];
	else if (keyCode == DOWN_ARROW)
		dir = [0, 1];


	if (keyCode == SHIFT) {
		activePlayer += 1;

		if (activePlayer >= players.length)
			activePlayer = 0;

		console.log(players[activePlayer].name);
	}

	if (keyCode == CONTROL) {
		activePlayer -= 1;

		if (activePlayer < 0)
			activePlayer = players.length - 1;

		console.log(players[activePlayer].name);
	}
}

function keyReleased() {
	dir = [0, 0];
}