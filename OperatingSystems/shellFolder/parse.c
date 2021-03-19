char **parse_cmdline( const char *cmdline ){
	const char *str = cmdline;
	int i;
	int space_counter = 2;

	for(i = 0; str[i] != '\n'; i++){
		if(str[i] == ' '){
			space_counter++;
		}
	}
	int sizecmd = i;

	char **dyn_arr = (char *) malloc(space_counter * sizeof(char *));
	char *dyn_str = (char *) malloc(sizecmd);
	int index_of_space = 0;
	int j = 0;

	for(i = 0; str[i]!='\n'; i++){
		if(str[i] != ' '){
			dyn_str[i - index_of_space] = str[i];
		}
		if(str[i] == ' '){
		dyn_str[i - index_of_space] = 0;
		//printf("%s ", dyn_str);
		dyn_arr[j] = dyn_str;
		j++;
		index_of_space = i + 1;
		dyn_str = (char *) malloc(sizecmd);
			
		}					

	}
	dyn_str[i - index_of_space] = 0;
	dyn_arr[j] = dyn_str;
	dyn_arr[j+1] = NULL;

	return dyn_arr;
}


char **parse_cmdline( const char *cmdline)
{

	char *temp_cmd_line = (char*)malloc((strlen(cmdline)+1)*sizeof(char));
	strcpy(temp_cmd_line, cmdline);

	char **cmd_args = (char**)malloc(sizeof(char*)*1);

	char *curr_tok = strtok(temp_cmd_line, " ");
	cmd_args[0] = curr_tok;
	int count = 1;

	/*
	int lenght = strlen(cmdline);
	char *curr_tok = malloc(lenght);
	strcpy(curr_tok, strtok(temp_cmd_line, " "));
	//curr_tok = strtok(temp_cmd_line, " ");
	cmd_args[0] = curr_tok;
	int count = 1;
	*/
	
	////Count segm
	////Allocate space 
	///

	while(1)
	{
		curr_tok = strtok(NULL, " ");
		if(curr_tok == NULL)
		{
			break;
		}
		cmd_args = (char**)realloc(cmd_args, (count+1) * sizeof(char*));
		cmd_args[count] = curr_tok;
		count++;
		//printf("%s\n", curr_tok);
		//printf("%ld\n", sizeof(curr_tok));
		
	}

	cmd_args = (char**)realloc(cmd_args, (count+1) * sizeof(char*));
	cmd_args[count] = NULL;



	/*printf("%d\n", count);
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", cmd_args[i]);
	}
	*/
	
	//printf("first:%s", cmd_args[0]);
	//printf("%ld\n", strlen(cmd_args[0]));
	//temp_cmd_line = NULL;
	//free(temp_cmd_line);
	return cmd_args;
}



char **parse_cmdline( const char *cmdline )
{
	int lenght = strlen(cmdline);

	int count_args = 1;
	for(int i = 0; i < lenght; i++)
	{
		if(cmdline[i] == ' ')
		{
			count_args++;
		}
	}


	char **cmd_args = (char **) malloc((count_args+1) * sizeof(char *));

	//int previous_space_index = 0;


	int counter = 0;
	for (int arg_index = 0; arg_index < count_args; arg_index++)
	{	
		char *curr_tok = (char *) malloc(sizeof(char) * 1);
		int curr_tok_size = 1;
		while(counter < lenght+1)///+1
		{
			if(cmdline[counter] == ' ' || cmdline[counter] == '\0')
			{
				curr_tok[curr_tok_size-1] = '\0';
				counter++;
				break;
			}
			curr_tok[curr_tok_size-1] = cmdline[counter];
			curr_tok_size++;
			curr_tok = (char*)realloc(curr_tok, curr_tok_size*sizeof(char));
			counter++;
		}
		cmd_args[arg_index] = malloc((strlen(curr_tok)+1)* sizeof(char));
		strcpy(cmd_args[arg_index], curr_tok);
		free(curr_tok);

	}
	cmd_args[count_args] = NULL;

	//cmd_args[arg_index + 1] = NULL;

	/*printf("%d\n", count_args);
	for (int i = 0; i < count_args; i++)
	{
		printf("%s\n", cmd_args[i]);
	}
	*/



	return cmd_args;
}





&& (cmdline[counter-1] != ' ')



/*	char *curr_tok;
	int curr_tok_size = 0;
	while(counter < lenght+1)
	{
		if((cmdline[counter] == ' ' || cmdline[counter] == '\0'))
		{
			curr_tok[curr_tok_size] = '\0';
			cmd_args[arg_index] = malloc((strlen(curr_tok)+1)* sizeof(char));
			strcpy(cmd_args[arg_index], curr_tok);
			free(curr_tok);
			arg_index++;
			curr_tok_size = 0;
			was 
		}
		else if(cmdline[counter] != ' ')
		{
			if(curr_tok_size == 0)
			{
				curr_tok = (char *) malloc(sizeof(char) * 1);
			}
			curr_tok[curr_tok_size] = cmdline[counter];
			curr_tok_size++;
			curr_tok = (char*)realloc(curr_tok, (curr_tok_size+1)*sizeof(char));
		}
		counter++;
	}
	cmd_args[count_args] = NULL;
*/





/*	while(arg_index < count_args)
	{	
		char *curr_tok = (char *) malloc(sizeof(char) * 1);
		int curr_tok_size = 1;
		while(counter < lenght+1)///To set last elem of last argument '\0'
		{
			if(cmdline[counter] == ' ' || cmdline[counter] == '\0')
			{
				curr_tok[curr_tok_size-1] = '\0';
				counter++;
				break;
			}
			else
			{
				curr_tok[curr_tok_size-1] = cmdline[counter];
				curr_tok_size++;
				curr_tok = (char*)realloc(curr_tok, curr_tok_size*sizeof(char));
				counter++;	
			}
		}
		cmd_args[arg_index] = malloc((strlen(curr_tok)+1)* sizeof(char));
		strcpy(cmd_args[arg_index], curr_tok);
		free(curr_tok);
		arg_index++;
	}
	cmd_args[count_args] = NULL;
	

	printf("%d\n", count_args);
	for (int i = 0; i < count_args; i++)
	{
		printf("%s\n", cmd_args[i]);
	}
	
*/