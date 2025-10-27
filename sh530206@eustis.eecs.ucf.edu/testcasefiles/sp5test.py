#Dr. Andrew Steinberg
#COP3223 Student Python Script v2.0 for Small Program 5
#This script will automatically compile, run, and compare your results to a provided txt file that contains sample output.
#DO NOT MODIFY THE CONTENTS OF THIS FILE!
#You do not need understand this code as this is out of the scope of this course. However, if you are interested you can discuss with Dr. Steinberg
#New to v2.0 update, a diff function was created to help student see where there error lies in output and now students will have 5 test cases

import os
import sys
import subprocess
import functools

#this is where we will put the input... yes they are global variables but this is ok to do for this scenario since this is a script
#it is list and each item will be string representing input for each question
#example  ['1 2 3', '2' , '4.2 41.4']
qinputs1 = ['4\n10\n101\n56\n89\n0\n'] 
qinputs2 = ['1\n12\n3\n412\n35\n7\n1239\n58\n234\n603\n7\n123\n-1\n'] 
qinputs3 = ['9\n123487\n541\n2\n345\n871\n26\n53\n7\n4612\n534\n76\n12\n8376\n42\n3985\n672\n3\n876\n4123\n465\n28\n963\n692\n354\n765\n123\n74\n700\n0\n'] 
qinputs4 = ['5\n250\n411\n118\n178\n233\n396\n432\n30\n370\n392\n382\n386\n214\n429\n394\n355\n52\n121\n152\n247\n464\n63\n50\n343\n454\n288\n449\n39\n342\n129\n0\n'] 
qinputs5 = ['3\n348\n238\n351\n452\n26\n2\n223\n58\n333\n315\n328\n7\n307\n458\n119\n282\n247\n398\n132\n500\n326\n10\n341\n198\n406\n325\n278\n92\n269\n288\n212\n162\n434\n229\n491\n399\n362\n35\n453\n222\n-1\n'] 
testcases = [qinputs1, qinputs2, qinputs3, qinputs4, qinputs5]




def diff(l1, l2):
    for line in range(0, len(l1)):
        line1 = l1[line]
        
        line2 = ""
        if line < len(l2):
            line2 = l2[line]
            
        if line1 != line2:
            print("These two lines are different in the terminal output")
            print("Steinberg Output: " + line1)
            print("Student's Output: " + line2)
            
    if len(l1) != len(l2):
        print("------------------------------------------------")
        print("Your output is missing content on certain lines.")
        print("------------------------------------------------")
        
def diffFileRecords(l1, l2):
    for line in range(0, len(l1)):
        line1 = l1[line]
        
        line2 = ""
        if line < len(l2):
            line2 = l2[line]
            
        if line1 != line2:
            print("The Problem 3 Solution Output Text File does not match.")
            print("These two lines are different in the text file")
            print("Steinberg Output: " + line1)
            print("Student's Output: " + line2)
            
    if len(l1) != len(l2):
        print("---------------------------------------------------")
        print("Your text file is missing content on certain lines.")
        print("---------------------------------------------------")
        

def diffFileNums(l1, l2):
    for line in range(0, len(l1)):
        line1 = l1[line]
        
        line2 = ""
        if line < len(l2):
            line2 = l2[line]
            
        if line1 != line2:
            print("The Problem 4 Solution Output File does not match.")
            print("These two lines are different in the text file")
            print("Steinberg Output: " + line1)
            print("Student's Output: " + line2)
            
    if len(l1) != len(l2):
        print("--------------------------------------------------")
        print("Your text file is missing content on certain lines.")
        print("--------------------------------------------------")


def result():
    cwd = os.getcwd()

    scenario = 1
    
    passes = 0
    
    for test in testcases:
        f1 = open(cwd + '/samplesolutionsp5testcase' + str(scenario) + '.txt', "r")
        f2 = open('sp5student_output_test_case_' + str(scenario) + '.txt', "r")
        f3 = open('recordsales_testcase_' + str(scenario)+ '.txt', "r")
        f4 = open('steinbergrecordsales_testcase_' + str(scenario)+ '.txt', "r")
        f5 = open('numfact_testcase_' + str(scenario)+ '.txt', "r")
        f6 = open('steinbergnumfact_testcase_' + str(scenario)+ '.txt', "r")
        
        #remove leading and trailing whitespace
        l1prestrip = f1.readlines()
        l2prestrip = f2.readlines()
        l3prestrip = f3.readlines()
        l4prestrip = f4.readlines()
        l5prestrip = f5.readlines()
        l6prestrip = f6.readlines()
        
        #remove leading and trailing whitespace
        l1 = [s.strip() for s in l1prestrip]
        l2 = [s.strip() for s in l2prestrip]
        l3 = [s.strip() for s in l3prestrip]
        l4 = [s.strip() for s in l4prestrip]
        l5 = [s.strip() for s in l5prestrip]
        l6 = [s.strip() for s in l6prestrip]
        
        
        #compare the content read
        if (len(l1) == len(l2) and functools.reduce(lambda x, y : x and y, map(lambda p, q: p == q, l1, l2), True)) and (len(l3) == len(l4) and functools.reduce(lambda x, y : x and y, map(lambda p, q: p == q, l3, l4), True)) and (len(l5) == len(l6) and functools.reduce(lambda x, y : x and y, map(lambda p, q: p == q, l5, l6), True)):
            print("TEST CASE " + str(scenario) + " PASSED!")
            passes = passes + 1
        else: 
            print("TEST CASE " + str(scenario) + " FAILED!")
            inputs = ' '.join([str(item) for item in test])
            print("The inputs used for this test case were " + inputs.replace('\n', ' '))
            diff(l1, l2)
            diffFileRecords(l4, l3)
            diffFileNums(l6, l5)
        
        scenario = scenario + 1
    
    if passes == 5:
        print("  ------  ")
        print(" / o  o \ ")
        print("|        |")
        print("| \____/ |")
        print(" \      / ")
        print("  ------  ")
        print("YESSSSS!!! ALL TEST CASES PASSED!")
        print("DISCLAIMER! MAKE SURE TO CHECK YOUR CODE THAT YOU FOLLOWED ALL DIRECTIONS THE ASSIGNMENT ASKS FOR. REGARDLESS OF THE CORRECT OUTPUT, DR. STEINBERG AND HIS TAs WILL CHECK YOUR CODE TO ENSURE DIRECTIONS WERE FOLLOWED FOR EACH PROBLEM! This includes code style!")
    else:
        os.system("cowsay -f eyes Boo! I did not mean to scare you even though it is spooky season. I just magically appear when your code did not pass any of the test cases your professor gave you! Pointers and File I/O can be a bit scary to understand, but with hard work and practice you will conquer this topic.")

    
    f1.close()
    f2.close()
    
    

def compilerunfile():
    cwd = os.getcwd()
    
    #gcc compile command the executable will be smallprogram 4 instead of a.out

    for subdir, dirs, files in os.walk(cwd):
        for myfile in files:
            if myfile[:13] == 'smallprogram5' and myfile[-2:] == '.c':
                gcccmd = "gcc -o " + "smallprogram5 " + myfile + " -lm" #compile solution file command and generate executable called smallprogram4

                proc = subprocess.run([gcccmd], capture_output=True, text = True, shell = True)
                
                if(len(str(proc.stderr)) > 0):
                    print("Ugh oh... Your program had warning/error messages! Try to fix them or else points are deducted.")
                    print("------------------------------------------------------------------------")
                    print(str(proc.stderr))
                    print("------------------------------------------------------------------------")
        break
    
    crun = "./" + "smallprogram5"
    
    
    
    
    scenario = 1
    for test in testcases:
    
        #list comprehension
        inputs = ' '.join([str(item) for item in test])
        f = open('sp5student_output_test_case_' + str(scenario) + '.txt', "w")
        f.write("----------------------------------------------------------------------\n")
        f.write("Testing Test Case " + str(scenario) + "\n")
        f.write("----------------------------------------------------------------------\n")
        
        
        try:
            
            #problem 2 text files
            os.rename("grades1_testcase" + str(scenario) + ".txt", "grades1.txt")
            os.rename("grades2_testcase" + str(scenario) + ".txt", "grades2.txt")
            os.rename("grades3_testcase" + str(scenario) + ".txt", "grades3.txt")
            
            
            
            
            #problem 3 text files
            os.rename("sales_testcase" + str(scenario) + ".txt", "sales.txt")
            
            #run test case
            proc2 = subprocess.run([crun], capture_output=True, input = inputs, text = True, shell = True, timeout= 2)
            
            
            #rename test case files back
            os.rename("grades1.txt", "grades1_testcase" + str(scenario) + ".txt")
            os.rename("grades2.txt", "grades2_testcase" + str(scenario) + ".txt")
            os.rename("grades3.txt", "grades3_testcase" + str(scenario) + ".txt")
            os.rename("sales.txt", "sales_testcase" + str(scenario) + ".txt")
            
            
            """os.rename("grades" + str(scenario) + ".txt", "grades.txt")
            proc2 = subprocess.run([crun], capture_output=True, input = inputs, text = True, shell = True, timeout= 2)
            os.rename("grades.txt", "grades" + str(scenario) + ".txt")"""
            f.write(str(proc2.stdout))
            f.close()

            
            if(len(str(proc2.stderr)) > 0):
                print("Ugh oh... Your program had error messages! Try to fix them or else points are deducted.")
                print("------------------------------------------------------------------------")
                print(str(proc2.stderr))
                print("------------------------------------------------------------------------")
            
        except subprocess.TimeoutExpired as e:
            
            if (e.stdout == None):
                print("Program Crashed for Test Case " + str(scenario) + ' with inputs ' + str(inputs))
                f.write("Program Crashed :( Please take a look at your logic in the code.")
            else:
                print("Your program is stuck in an infinite loop! Please make sure to fix that or else points are going to be deducted.")
            
            f.close()
        
        
 
        if(os.path.exists('recordsales.txt')):
            os.rename("recordsales.txt", "recordsales_testcase_" + str(scenario) + ".txt")
        else:
            with open("recordsales_testcase_" + str(scenario) + ".txt", 'w') as fp: #if does not exist to prevent FileNotFoundError
                pass
                
        
        if(os.path.exists('numfact.txt')):
            os.rename("numfact.txt", "numfact_testcase_" + str(scenario) + ".txt")
        else:
            with open("numfact_testcase_" + str(scenario) + ".txt", 'w') as fp: #if does not exist to prevent FileNotFoundError
                pass
        
        
        
        scenario = scenario + 1
    

    print("Done running the student's solution.")
    


def setupchecker():
    print("We are now checking to make sure you have all necessary files in the same directory.")
    cwd = os.getcwd() #this grabs the current directory as it varies for each student based on NID
    
    #first check to see if solution txt file exists in the same directory as this script
    
    
    for x in range(1, 3):
        if not os.path.exists(cwd + "/samplesolutionsp5testcase" + str(x) + ".txt"):
            raise FileNotFoundError("The provided sample solution text file for test case " + str(x) + " is not in the currect directory as this script." + 
            " Please place the text file in this directory and try again. Script Exiting!")
       

    #check to see if c file is placed properly. Only checks parts of it. Student is responsible for naming it properly with respective name as stated in the directions.
    flag = 0
    for subdir, dirs, files in os.walk(cwd):
        for myfile in files:
            if myfile[:13] == 'smallprogram5' and myfile[-2:] == '.c':
                flag = 1
        break
    
    if flag == 0:
        raise FileNotFoundError("You are missing your C source!! Please put in your smallprogram5_lastname_firstname.c file. Script Exiting!")
        
    
    
    #15 files
    for x in range(1, 6):
        if not os.path.exists(cwd + "/grades1_testcase" + str(x) + ".txt") or not os.path.exists(cwd + "/grades2_testcase" + str(x) + ".txt") or not os.path.exists(cwd + "/grades3_testcase" + str(x) + ".txt"):
            raise FileNotFoundError("You are missing a grades test case file!")
    
    #5 files
    for x in range(1, 6):
        if not os.path.exists(cwd + "/sales_testcase" + str(x) + ".txt"):
            raise FileNotFoundError("You are missing a sales test case file!")
    
    #5 files
    for x in range(1, 6):
        if not os.path.exists(cwd + "/steinbergnumfact_testcase_" + str(x) + ".txt"):
            raise FileNotFoundError("You are missing a num fact test case file!")
    
    #5 files
    for x in range(1, 6):
        if not os.path.exists(cwd + "/steinbergrecordsales_testcase_" + str(x) + ".txt"):
            raise FileNotFoundError("You are missing a record sales test case file!")
    
    
    if os.path.exists(cwd + "/grades1.txt"):
        os.rename("grades1.txt", "grades1temp.txt")
        
    if os.path.exists(cwd + "/grades2.txt"):
        os.rename("grades2.txt", "grades2temp.txt")
        
    if os.path.exists(cwd + "/grades3.txt"):
        os.rename("grades3.txt", "grades3temp.txt")
        
    if os.path.exists(cwd + "/sales.txt"):
        os.rename("sales.txt", "salestemp.txt")
    
    print("We are done with checking to make sure necessary files were provided.")
  
"""resets the files from manual testing"""
def reset():
    cwd = os.getcwd()
    if os.path.exists(cwd + "/grades1temp.txt"):
        os.rename("grades1temp.txt", "grades1.txt")
        
    if os.path.exists(cwd + "/grades2temp.txt"):
        os.rename("grades2temp.txt", "grades2.txt")
        
    if os.path.exists(cwd + "/grades3temp.txt"):
        os.rename("grades3temp.txt", "grades3.txt")
        
    if os.path.exists(cwd + "/salestemp.txt"):
        os.rename("salestemp.txt", "sales.txt")


def main():
    print("Beginning the test of my program compared with a provided txt file from Dr. Steinberg.")
    print("Before this script tests the program, we need to make sure you have everything in order.")
    setupchecker()
    print("Setup is now complete. Begin testing.")
    print("Now it is time to compile the file.")
    compilerunfile()
    print("Now it is time for the moment of truth. Comparing my file output with Dr. Steinberg's sample solution file.")
    result()
    
    reset()

    
    
    

if __name__ == "__main__":
    main()