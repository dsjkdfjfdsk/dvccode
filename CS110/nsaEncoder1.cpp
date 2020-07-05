

  //program introduction
  introduction(objective);

  //get user input for file name and open that and the output file
  cout << "Please type in a name of the file (with the .txt extension) : ";
  cin >> filename;
  cin.ignore(1000, 10);
  fin.open(filename.c_str());
  if (!fin.good()) throw "I/O error"; 
  fout.open("secret.txt");
  if (!fout.good()) throw "I/O error"; 
  
  //encodes every line in the input file and outputs the result to secret.txt
  whil
}
