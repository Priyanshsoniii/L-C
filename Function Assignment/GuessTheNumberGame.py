import random

def is_number_integer(input_number):
    return input_number.isdigit()

def is_integer_in_range(input_number):
    return 1 <= int(input_number) <= 100

def validate_number(input_number):
    return is_number_integer(input_number) and is_integer_in_range(input_number)

def get_valid_user_guess():
    while True:
        guessed_number = input("Guess a number between 1 and 100: ")
        if validate_number(guessed_number):
            return int(guessed_number)
        print("Invalid input. Please enter a number between 1 and 100.")

def play_guess_the_number_game():
    target_number = random.randint(1, 100)
    guess_count = 0
    is_guess_correct = False
    
    while not is_guess_correct:
        guessed_number = get_valid_user_guess()
        guess_count += 1
        
        if guessed_number < target_number:
            print("Too low. Guess again.")
        elif guessed_number > target_number:
            print("Too high. Guess again.")
        else:
            print(f"You guessed it in {guess_count} guesses!")
            is_guess_correct = True

def main():
    play_guess_the_number_game()

main()