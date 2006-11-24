dd ()
{
  switch (j)
    {
    case 'l': case 'p':
      switch (f) {
      case 'g': case 'h': getchar (); break;
      case 'p': case 's': break;
      default: gg(); break;
      } break;
    case 'y': print (); break;
    }
  call_me ("finished");
}
