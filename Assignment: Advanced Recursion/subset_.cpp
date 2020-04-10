int subset(int input[], int n, int output[][20]) 
{
  if(n == 0)
  {
    output[0][0] = 0;
    return 1;
  }

  int digit = input[0];
  int size = subset(input + 1, n-1, output);

  for(int j=0; j<size; j++)
  {
    output[size + j][0] = output[j][0] + 1;
    output[size + j][1] = input[0]; 
    for(int k=1; k<=output[j][0]; k++)
    {
      output[size + j][k+1] = output[j][k];
    }
  }

  return (2*size);
}
