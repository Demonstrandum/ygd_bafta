var players = [];
var playerlist = [];
var platforms = [];

var activePlayer = 0;
var dir = [0, 0];

function setup() {
	createCanvas(600, 400);

	//Player Setup
	players.push(...[
		new Player('Cube', 0, 0, 10, 10, [255, 0, 100]),
		new Player('Rectangle', 20, 0, 10, 20, [200, 200, 0]),
		new Player('BigCube', 40, 0, 40, 40, [0, 0, 255]),
		new Player('FlatRectagle', 0, 50, 80, 10, [0, 200, 100])
	]);
	playerlist.push(...[
		new Player('Cube', width - 50, 20, 10, 10, [255, 0, 100]),
		new Player('Rectangle', width - 50, 40, 10, 20, [200, 200, 0]),
		new Player('BigCube', width - 50, 70, 40, 40, [0, 0, 255]),
		new Player('FlatRectagle', width - 50, 120, 80, 10, [0, 200, 100])
	]);
	//Level Setup
	platforms.push(...[
		new Player('Right List', width - 100, 0, 100, height, [0, 0, 0]),
		new Player('Floor', 0, height - 100, width, 100, [255, 255, 255])
	]);


}

function draw() {
	background(0);

	//Move Active Player
	players[activePlayer].move(dir);

	//Render Players
	for (var i = 0; i < players.length; i++) {
		players[i].gravity();
		players[i].collision(players);
		players[i].collision(platforms);
		players[i].render();
	}

	//Render Platforms
	for (var i = 0; i < platforms.length; i++) {
		platforms[i].render();
	} for (var i = 0; i < players.length; i++) {
		playerlist[i].render();
	}
}

function keyPressed() {
	if (keyCode == RIGHT_ARROW)
		dir = [1, 0];
	else if (keyCode == LEFT_ARROW)
		dir = [-1, 0];
	if (keyCode == UP_ARROW)
		if (players[activePlayer].canjump) {
			players[activePlayer].canjump= false;
			players[activePlayer].grav = -2;
		}


	if (keyCode == CONTROL) {
		activePlayer += 1;

		if (activePlayer >= players.length)
			activePlayer = 0;

		console.log(players[activePlayer].name);
	}

	if (keyCode == SHIFT) {
		activePlayer -= 1;

		if (activePlayer < 0)
			activePlayer = players.length - 1;

		console.log(players[activePlayer].name);
	}
}

function keyReleased() {
	dir = [0, 0];
}
