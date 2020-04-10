bool check_recAB(char input[])
{
    if (input[0] == '\0') return true;
    if (input[0] == 'a') return check_recAB(input + 1);
    else if (input[1] == 'b') return check_recAB(input + 2);
    return false;
}

bool checkAB(char input[]) 
{
	// Write your code here
	if (input[0] != 'a') return false;
    return check_recAB(input);
}
