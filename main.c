#include <stdio.h>
#include <stdlib.h>  // malloc(), realloc(), free()
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()
#include "vectorLL.h"
#include "moreMath.h"
#include "vectorPJ.h"

struct sporadicJob{
	int period;
	float executionTime;
	int actualArrivalTime;
	float remainingExecutionTime;
	int relativeDeadline;
	int absoluteDeadline;
	int timesExecuted;
};
typedef struct sporadicJob sporadicJob;

struct aPeriodicJob{
	int arrivalTime;
	float executionTime;
	float remainingExecutionTime;
	int relativeDeadline;
	int absoluteDeadline;
};
typedef struct aPeriodicJobs aPeriodicJobs;

int main(int argc, char const *argv[])
{
	printf("\n");
	srand(time(0));
	FILE* periodicJobsFile=fopen("periodicJobs.txt","r");
	
	if(periodicJobsFile==NULL)
	{
		printf("./periodicJobs.txt can't be found. Please keep the file in the same directory as the executable.\n");
		return 1;
	}
	
	int numPeriodicJobs=0;
	//First line of the file will be the number of periodic jobs
	fscanf(periodicJobsFile,"%d",&numPeriodicJobs);
	periodicJob periodicJobList[2*numPeriodicJobs+1];
	
	long long hyperperiod=1;
	
	//Frame size has to be smaller than the minimum period
	int minPeriod=__INT_MAX__;
	//Frame size has to be larger than the maximum execution time
	int maxExecutionTime=0;
	int maxExecutionIndex=0;
	/* 
	 * Each job will be described by a line in the file.
	 * Each line will have the following format:
	 * period, execution time, relative Deadline in that order
	*/
	for (int i=0; i<numPeriodicJobs; i++){
		fscanf(periodicJobsFile,"%d %f %d",
			&periodicJobList[i].period,
			&periodicJobList[i].executionTime,
			&periodicJobList[i].relativeDeadline);
		
		//Actual execution time can be anything between 20 and 100 perecent of WCET
		float randomFactor=(rand()%(8))+2;
		periodicJobList[i].executionTime*=(randomFactor/10.0);
		periodicJobList[i].timesExecuted=0;
		periodicJobList[i].remainingExecutionTime=periodicJobList[i].executionTime;
		periodicJobList[i].absoluteDeadline=periodicJobList[i].relativeDeadline;
		//LCM(a,b,c) = LCM(a,LCM(b,c))
		hyperperiod=LCM(hyperperiod, periodicJobList[i].period);
		minPeriod=min(minPeriod,periodicJobList[i].period);
		if(periodicJobList[i].executionTime>maxExecutionTime){
			maxExecutionTime=periodicJobList[i].executionTime;
			maxExecutionIndex=i;
		}
	}
	fclose(periodicJobsFile);
	
	while(minPeriod<maxExecutionTime){
		printf("The frame has to be small enough to be contained inside every frame\n but also be bigger than the max execution time\nThis property is not being satisfied. We'll have to split the frame ");
		periodicJobList[maxExecutionIndex].executionTime/=2;
		periodicJobList[numPeriodicJobs++]=periodicJobList[maxExecutionIndex];
		minPeriod=__INT_MAX__;
		maxExecutionTime=0;
		maxExecutionIndex=0;
		
		//Keep splitting the job with maximum execution time until it's more than the minimum period
		for (long long i=0; i<numPeriodicJobs; i++){
			minPeriod=min(minPeriod,periodicJobList[i].period);
			if(maxExecutionTime<periodicJobList[i].executionTime){
				maxExecutionTime=periodicJobList[i].executionTime;
				maxExecutionIndex=i;
			}
		}
	}
	
	
	
	//Checking if utilization is less than 100%
	long long executionTimePerHyperperiod=0;
	for (long long i=0; i<numPeriodicJobs; i++){
		executionTimePerHyperperiod+=(periodicJobList[i].executionTime)*(hyperperiod/periodicJobList[i].period);
	}
	printf("Utilization is %.2f%%\n",100*((float)executionTimePerHyperperiod/(float)hyperperiod));
	if(executionTimePerHyperperiod>hyperperiod){
		printf("Impossible to accomodate all the jobs. Please reduce workload or increase period\n");
		return 1;
	}
	
	//Vector of long long that holds all factors of the hyperperiod
	vectorLL possibleFrameSizes=*vectorLLInit(&possibleFrameSizes);
	allFactors(hyperperiod, &possibleFrameSizes);
	int n=vectorLLSize(&possibleFrameSizes);
	
	//Binary Search to find the lowest index that has element greater than minPeriod
	int i=upperBound(&possibleFrameSizes, minPeriod);
	
	/* 
	 * Start checking from the smallest possible frame sizes
	 * so we could accomodate maximum sporadic and aperiodic jobs
	 * Question states to assume no overhead :)
	 */
	for(;i<n && vectorLLGet(&possibleFrameSizes,i)<=maxExecutionTime; i++){
		int f=vectorLLGet(&possibleFrameSizes,i);
		for(int i=0; i<numPeriodicJobs; i++){
			if(2*f-GCD(f,periodicJobList[i].period)>periodicJobList[i].relativeDeadline){
				break;
			}
		}
		break;
	}
	if(i==n){
		printf("No possible frame size found. Maximum Execution Time is also lesser than minimum Period...\n");
		return 1;
	}
	
	int frameSize=vectorLLGet(&possibleFrameSizes,i);
	printf("Framesize satisfying all constraints is %d\n",frameSize);
	
	// FILE* periodicScheduleFile=fopen("periodicSchedule.txt","w");

	//Creating a 2D array showing the various tasks of each job
	
	
	// int numberOfLines=hyperperiod/frameSize;
	// for (long long i=0; i<numberOfLines; i++){
	// 	for (long long j=0; j<numPeriodicJobs; j++){
			
	// 	}
	// 	// fprintf(periodicScheduleFile,"\n");
	// }
	
	// FILE* sporadicJobsFile=fopen("sporadicJobs.txt","r");
	
	// if(sporadicJobsFile==NULL)
	// {
	// 	printf("./sporadicJobs.txt can't be found. Please keep the file in the same directory as the executable.\n");
	// 	return 1;
	// }
	
	// int numSporadicJobs=0;
	// //First line of the file will be the number of sporadic jobs
	// fscanf(sporadicJobsFile,"%d",&numSporadicJobs);
	// sporadicJob sporadicJobList[numSporadicJobs];
	
	
	// for (int i=0; i<numSporadicJobs; i++){
	// 	fscanf(sporadicJobsFile,"%d %f %d",
	// 		&sporadicJobList[i].period,
	// 		&sporadicJobList[i].executionTime,
	// 		&sporadicJobList[i].actualArrivalTime);
		
	// 	float randomFactor=(rand()%(8))+2;
	// 	sporadicJobList[i].executionTime*=(randomFactor/10.0);
	// 	sporadicJobList[i].timesExecuted=0;
	// 	sporadicJobList[i].remainingExecutionTime=sporadicJobList[i].executionTime;
	// 	sporadicJobList[i].absoluteDeadline=sporadicJobList[i].relativeDeadline;
	// }
	
	// fclose(sporadicJobsFile);
	
	
	
	
}
