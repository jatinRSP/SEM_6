import numpy as np

# Human 'X' and AI 'O'

# Function to print the Tic-Tac-Toe board
def print_board(board):
    print("\n")
    print(" " + board[0] + " | " + board[1] + " | " + board[2])
    print("-----------")
    print(" " + board[3] + " | " + board[4] + " | " + board[5])
    print("-----------")
    print(" " + board[6] + " | " + board[7] + " | " + board[8])
    print("\n")

# Function to check if a player has won the game
def check_win(board, player):
    winning_conditions = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],
        [0, 3, 6], [1, 4, 7], [2, 5, 8],
        [0, 4, 8], [2, 4, 6]
    ]
    for condition in winning_conditions:
        if board[condition[0]] == player and board[condition[1]] == player and board[condition[2]] == player:
            return True
    return False

# Function to check if the game is a tie
def check_tie(board):
    return board.count(' ') == 0

# Minimax algorithm implementation for AI opponent
def minimax(board, player):
    if check_win(board, 'X'): return [-1, -1]
    elif check_win(board, 'O'): return [-1, 1]
    elif check_tie(board): return [-1, 0]

    best = [-1, -1000 if player == 'O' else 1000]

    for cell in range(9):
        if board[cell] == ' ':
            board[cell] = player
            score = minimax(board, 'O' if player == 'X' else 'X')
            board[cell] = ' '

            score[0] = cell
            if player == 'O':
                if score[1] > best[1]: best = score
            else:
                if score[1] < best[1]: best = score

    return best

# Function to get the opponent's move (human player)
def opponent_turn(board):
    cell = int(input("Enter cell number (1-9): ")) - 1
    if board[cell] != ' ':
        print("Invalid move. Try again.")
        opponent_turn(board)
    else:
        board[cell] = 'X'

# Function to make the AI opponent's move using minimax
def player_turn(board):
    move = minimax(board, 'O')
    board[move[0]] = 'O'

# Main function to run the Tic-Tac-Toe game
def main():
    board = [' ']*9
    print_board(board)

    while True:
        opponent_turn(board)
        print_board(board)

        if check_win(board, 'X'):
            print("Human wins!")
            break
        elif check_tie(board):
            print("It's a tie!")
            break

        player_turn(board)
        print_board(board)

        if check_win(board, 'O'):
            print("AI win!")
            break
        elif check_tie(board):
            print("It's a tie!")
            break

if __name__ == "__main__":
    main()