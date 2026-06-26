import random

class Player:
    def __init__(self, name):
        self.name = name
        self.position = 0
    
    def move(self, steps):
        self.position += steps

class SnakeAndLadders:
    def __init__(self, size):
        self.size = size
        self.board = {}
        self.players = []
    
    def add_snake_or_ladder(self, start, end):
        self.board[start] = end
    
    def roll_dice(self):
        return random.randint(1, 6)
    
    def is_snake_or_ladder(self, position):
        return position in self.board
    
    def move_player(self, player):
        steps = self.roll_dice()
        print(f"{player.name} rolled a {steps}.")
        player.move(steps)
        if self.is_snake_or_ladder(player.position):
            new_position = self.board[player.position]
            if new_position < player.position:
                print(f"Oops! {player.name} encountered a snake and moved to position {new_position}.")
            else:
                print(f"Wow! {player.name} found a ladder and moved to position {new_position}.")
            player.position = new_position
    
    def play_game(self):
        while True:
            for player in self.players:
                self.move_player(player)
                if player.position >= self.size:
                    print(f"Congratulations! {player.name} wins!")
                    return
    
    def add_player(self, name):
        self.players.append(Player(name))

game = SnakeAndLadders(100)
game.add_snake_or_ladder(14, 4)
game.add_snake_or_ladder(17, 7)
game.add_snake_or_ladder(54, 34)
game.add_snake_or_ladder(64, 60)
game.add_snake_or_ladder(87, 24)

game.add_player("Player 1")
game.add_player("Player 2")

game.play_game()
