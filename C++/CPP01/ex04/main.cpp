/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btani <btani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:40:27 by btani             #+#    #+#             */
/*   Updated: 2024/02/01 18:31:08 by btani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

//it copies a file in file.replace and replace each occurency of s1 in s2
void replaceStr( std::string& str, const std::string& s1, const std::string& s2 ) 
{
    std::string output;
    for (std::size_t len = 0; len < str.length();)
    {
        if (str.substr(len, s1.length()) == s1)
        {
            output += s2;
            len += s1.length();
        }
        else
        {
            output += str[len];
            len++;
        }
    }
    str = output;
};

//ifstream: Stands for input file stream, for reading data from files. 
//ofstrem: Stands for output file stream, for writing data to files.
int main( int ac, char* av[] )
{ 
    if (ac != 4)
    {
        std::cerr << "Invalid arguments. Usage: " << av[0] << " 'file' <s1> <s2>" << std::endl;
        return 1; 
    }

    std::string in_filename = av[1];
    std::string out_filename = in_filename + ".replace";
    std::ifstream inputFile(in_filename.c_str());
	std::ofstream outputFile(out_filename.c_str());
    
    if (!inputFile.is_open())
    {
        std::cerr << "Error: impossible opening the input file." << std::endl;
        inputFile.close();
        return 1;
    }
    if (!outputFile.is_open())
    {
        std::cerr << "Error: impossible opening the output file." << std::endl;
        inputFile.close();
        return 1;
    }
    std::string str;
    while(std::getline(inputFile, str))
    {
        replaceStr(str, av[2], av[3]);
        outputFile << str << std::endl;
    }
    inputFile.close();
    outputFile.close();
    
    std::cout << "File successfully replaced. Output saved to " << in_filename + ".replace" << std::endl;
    return 0;
}
