#include<stdio.h>

void openingTheFileInTheReadModeWhereTheFileDoesnotExist() {

    // Opening the File in the read Mode
    FILE* sampleFile = fopen("randomFile.txt", "r");

    if (sampleFile == NULL) {
        printf("R mode fails if the files does not exists\n");
    } else {
        // Just in case the file exists we are closing it.
        fclose(sampleFile);
    }
}

void openingTheFileInTheReadModeWhereTheFileDoesExist() {
    // Opening the File in the read Mode
    FILE* sampleFile = fopen("helloWorld.txt", "r");
   
    char* line1;
   
     // Getting the First 100 Characters or till the Lines Get Terminated either by Null or \n.
    fgets(line1, 100, sampleFile);


    //Printing using the fprintf , Printing in the FILE* stdout.
    fprintf(stdout, "Here is the First Line : %s" , line1);

    //or We can print directly since we know that printf will automatically print to the stdout.
    printf("Here is the First Line : %s" , line1);

    //Closing the File
    fclose(sampleFile);
}

void CreatingAndWritingReadingInTheBinaryFile() {
    FILE *writeFile = fopen("binary_data.bin", "wb"); // Open for writing in binary mode

    if (writeFile == NULL) {
        perror("Error opening file for writing");
        return;
    }

    int data[] = {10, 20, 30, 40, 50};
    size_t dataSize = sizeof(data) / sizeof(data[0]);

    fwrite(data, sizeof(int), dataSize, writeFile);

    fclose(writeFile);

    // Reading from a binary file
    FILE *readFile = fopen("binary_data.bin", "rb"); // Open for reading in binary mode

    if (readFile == NULL) {
        perror("Error opening file for reading");
        return;
    }

    int readData[dataSize];

    fread(readData, sizeof(int), dataSize, readFile);

    for (size_t i = 0; i < dataSize; i++) {
        printf("%d\n", readData[i]);
    }

    fclose(readFile);
}

int main() {
   
   printf("Testcase 1\n");
   openingTheFileInTheReadModeWhereTheFileDoesnotExist();


//     printf("Testcase 2\n");
   //     openingTheFileInTheReadModeWhereTheFileDoesExist();

    // printf("Testcase 3\n");
    //    CreatingAndWritingReadingInTheBinaryFile();
}