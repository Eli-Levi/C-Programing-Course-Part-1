#include <stdio.h>
#include <string.h>
#define WORD 30
#define LINE 256

int getWord(char w[])
{
  char c = getchar();
  int counter = 0;
  while ((c != '\t') && (c != ' ') && (c != '\n')&&(c != EOF) && c != 13)
  {
    w[counter] = c;
    ++counter;
    c = getchar();
  }
  
  if(c == EOF)
  {
    //printf("eof \n");
    w[0] = EOF;
    return 0;
  }
  w[counter] = '\0';
  return counter;
}

int get_save_line(char w[])
{
  char c=getchar();
  int counter = 0;
  while ((c != '\n') && (c != EOF))
  {
    w[counter] = c;
    ++counter;
    c = getchar();
  }
  w[counter] = '\0';
  if (c == EOF)
  {
    w[0] = EOF;
  }
  return counter;
}

int substring(char *container, char *contained)
{
  char *result = strstr(container, contained);
  if (result == NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void print_lines(char *str)
{
  char the_line_is[LINE];
  get_save_line(the_line_is);
  while (the_line_is[0] != EOF)
  {
    if (substring(the_line_is, str))
    {
      printf("%s\n", the_line_is);
    }
    get_save_line(the_line_is);
  }
}

int similar(char *search_word, char *searched_against, int number_of_errors)
{
  if (strlen(searched_against)<strlen(search_word))
  {
    return 0;
  }
  
  int epsilon = 0;
  int place = 0;
  for (int j = 0; j < strlen(searched_against); j++)
  {
    if (search_word[place] == searched_against[j])
    {
      place++;
    }

    else
    {
      epsilon++;
    }
  }
  if (epsilon > number_of_errors)
  {
    return 0;
  }
  return 1;
}

void print_similar_words(char *str)
{
  char line[WORD];
  getWord(line);
  while (line[0] !=EOF)
  {
    //printf("the first letter of line is: %i, the line is %s\n",line[0],line);
    if (similar(str, line,1))
    {
      printf("%s\n", line);
    }
    getWord(line);
  }
}

int main()
{
  char what_func[2];
  char search_word[WORD];
  getWord(search_word);
  getWord(what_func);
  getchar();
  //printf("word : %s\n",search_word);
  //printf("si = : %c\n",what_func[0]);
  switch (what_func[0])
  {
  case 'a':
    print_lines(search_word);
    return 0;
    break;

  case 'b':
    print_similar_words(search_word);
    return 0;
    break;

  default:
    printf("Pick a or b");
    break;
  }
  printf("THE END OF ALL THINGS!!!");
  return 0;
}
