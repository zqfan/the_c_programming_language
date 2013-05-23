/* Write an alternative version of squeeze(s1,s2) that deletes each
   character in s1 that matches any character in the string s2.
*/
#include<string.h>
#include<assert.h>

/* delete all characters in s2 from s1, only support ASCII string.
   i just loop two strings with O(M*N) cost, if s1 or s2 is very
   large, it can be optimized by make a 256 bool array indicates all
   ASCII character appearance in s2, which will reduce cost to O(M)
   + O(N)
*/
void squeeze(char * s1, const char * s2)
{
  int i, j, k;
  for (i = k = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++)
      ;
    /* not found s1[i] in s2 */
    if (s2[j] == '\0')
      s1[k++] = s1[i];
  }
  s1[k] = '\0';
}

int main()
{
  char s[] = "happy programmer:)";
  squeeze(s, "ram");
  assert(strcmp(s, "hppy poge:)") == 0);
  squeeze(s, "");
  assert(strcmp(s, "hppy poge:)") == 0);
  char s2[] = "";
  squeeze(s2, "abc");
  assert(strcmp(s2, "") == 0);
  return 0;
}
