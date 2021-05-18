#include <iostream>
#include <istream>
#include "Controller.h"


//aici trebuie sa apelez functiile din repo si sa le bag in listele in care am salvate fructele

Controller::Controller(Repo& repo) : repo(repo)
{
}

Repo Controller::get_repo() {
	return this->repo;
}

void Controller::populate(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index) {
	repo.populate(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, index);
}

void Controller::set_role(string passwd) {
	repo.set_role(passwd);
}

void Controller::addFunction(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index)
{
	repo.add_auto(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, index);
}

void Controller::removeFunction(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index)
{
	repo.del_auto(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, index);
}

void Controller::updateFunction(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int new_kilometer, int new_preis, int index)
{
	Auto a(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, index);
	repo.update_auto(a, new_kilometer, new_preis);
}

vector < Auto> Controller::serachNachMarkeModell(string marke, string modell)
{
	return repo.search(marke, modell);
}

vector < Auto> Controller::filterNachAlter(int alter) {
	return repo.auto_filter_alter(alter);
}

vector < Auto> Controller::filterNachKm(int km) {
	return repo.auto_filter_km(km);
}

vector <Auto> Controller::sortierenFunction()
{
	return repo.auto_sort_preis();
}

void Controller::add_favorite(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int role, int index) {
	Auto a(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, index);
	repo.add_fav(a, role);
}
vector <Auto> Controller::see_fav(int role) {
	return repo.see_fav(role);
}


void create_Autos_File() 
{
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("Files.csv", ios::out | ios::app);

    string modell;
    string marke;
    int erstzulassung;
    int kilometer;
    int preis;
    int leistung;
    string treibstoff;
    int index;

    // Read the input
    cin >> modell >> marke >> erstzulassung >> kilometer >> preis >> leistung >> treibstoff >> index;

        // Insert the data to file
        fout << modell << ", " << marke << ", " << erstzulassung << ", " << kilometer << ", " << preis << ", ";
        fout << leistung << ", " << treibstoff << ", " << index << "\n";

}

void delete_Autos_File()
{
    // Open FIle pointers
    fstream fin, fout;

    // Open the existing file
    fin.open("Files.csv", ios::in);

    // Create a new file to store the non-deleted data
    fout.open("Files.csv", ios::out);

    int rollnum, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;

    // Get the roll number
    // to decide the data to be deleted
    cout << "Schreiben Sie den Index des Autos welche Sie loschen mochten ";
    cin >> rollnum;

    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof()) {

        row.clear();
        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ', ')) {
            row.push_back(word);
        }

        int row_size = row.size();
        roll1 = stoi(row[0]);

        // writing all records,
        // except the record to be deleted,
        // into the new file 'reportcardnew.csv'
        // using fout pointer
        if (roll1 != rollnum) {
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ", ";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Auto ist geloscht\n";
    else
        cout << "Auto nicht gefunden\n";

    // Close the pointers
    fin.close();
    fout.close();

    // removing the existing file
    remove("Files.csv");

    // renaming the new file with the existing file name
    rename("Files.csv", "Files.csv");
}

void update_Autos_File()
{
    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("Files.csv", ios::in);

    // Create a new file to store updated data
    fout.open("Files.csv", ios::out);

    int rollnum, roll1, marks, count = 0, i;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;

    // Get the roll number from the user
    cout << "Schreiben Sie den Index des Autos welche Sie verandern mochten (E/K/P/L/T)";
    cin >> rollnum;

    // Get the data to be updated
    cout << "Was mochten Sie verandern ?";
    cin >> sub;

    // Determine the index of the subject
    // where Maths has index 2,
    // Physics has index 3, and so on
    if (sub == 'e' || sub == 'E')
        index = 2;
    else if (sub == 'k' || sub == 'K')
        index = 3;
    else if (sub == 'p' || sub == 'P')
        index = 4;
    else if (sub == 'l' || sub == 'L')
        index = 5;
    else if (sub == 't' || sub == 'T')
        index = 6;
    else {
        cout << "Auswahl nicht gefunden, versuchen Sie noch ein Mal\n";
        update_Autos_File();
    }

    // Get the new marks
    cout << "Schreiben Sie den neuen Wert: ";
    cin >> new_marks;

    // Traverse the file
    while (!fin.eof()) {

        row.clear();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ', ')) {
            row.push_back(word);
        }

        roll1 = stoi(row[0]);
        int row_size = row.size();

        if (roll1 == rollnum) {
            count = 1;
            stringstream convert;

            // sending a number as a stream into output string
            convert << new_marks;

            // the str() converts number into string
            row[index] = convert.str();

            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {

                    // write the updated data
                    // into a new file 'reportcardnew.csv'
                    // using fout
                    fout << row[i] << ", ";
                }

                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {

                    // writing other existing records
                    // into the new file using fout.
                    fout << row[i] << ", ";
                }

                // the last column data ends with a '\n'
                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }
    if (count == 0)
        cout << "Record not found\n";

    fin.close();
    fout.close();

    // removing the existing file
    remove("reportcard.csv");

    // renaming the updated file with the existing file name
    rename("reportcardnew.csv", "reportcard.csv");

}


#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

std::vector<std::pair<std::string, std::vector<int>>> read_csv(std::string Files) 
{
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<std::pair<std::string, std::vector<int>>> result;

    // Create an input filestream
    std::ifstream myFile(Files);

    // Make sure the file is open
    if (!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    std::string line, colname;
    int val;

    // Read the column names
    if (myFile.good())
    {
        // Extract the first line in the file
        std::getline(myFile, line);

        // Create a stringstream from line
        std::stringstream ss(line);

        // Extract each column name
        while (std::getline(ss, colname, ',')) {

            // Initialize and add <colname, int vector> pairs to result
            result.push_back({ colname, std::vector<int> {} });
        }
    }

    // Read data, line by line
    while (std::getline(myFile, line))
    {
        // Create a stringstream of the current line
        std::stringstream ss(line);

        // Keep track of the current column index
        int colIdx = 0;

        // Extract each integer
        while (ss >> val) {

            // Add the current integer to the 'colIdx' column's values vector
            result.at(colIdx).second.push_back(val);

            // If the next token is a comma, ignore it and move on
            if (ss.peek() == ',') ss.ignore();

            // Increment the column index
            colIdx++;
        }
    }

    // Close file
    myFile.close();

    return result;
}