
//place to save tasks
var taskArray = [];


//update task list
var updateTasks = function(){
		var taskListHolding = document.getElementById('taskList');
  
  //empty the task lisk
  taskListHolding.innerHTML='';
  //determine task list length
  var len = taskArray.length;
  var i;
  
  for(i=0; i<len; i++){
    console.log('task ' + i + ": " + taskArray[i]);
    //create element
    var newTask = document.createElement('div');

    //ddefine the div's ID and it's class
    newTask.id = i;
    newTask.className ='task';

     //create the task paragraph 
    var task = document.createElement('p');
    
    //assign the task to the task div
    task.innerHTML = taskArray[i];
    
    //create the delete button
    var deleteButton = document.createElement('button');
    //set the delete button ID to deleteButton
    deleteButton.id = 'deleteButton';
    //add a value to our button
    deleteButton.innerText='X';
    
    //listen for the click
    deleteButton.addEventListener('click', function(e){
      e.preventDefault();
      deleteTask(e);
    });
    
    //append the task to the taskdiv
    newTask.appendChild(task);
    
    //append the delete button to the newTask div
    newTask.appendChild(deleteButton);

    //append the taskDiv to the tasklistholding Div
    taskListHolding.appendChild(newTask);

    //append the tasklistholding Div to the body Div
    myAwesomeToDoList.appendChild(taskListHolding);

  };

  if (taskArray.length > 0){

    //create the deleleAll button
    var deleteAll = document.createElement("button");
    //set the deleteAll button ID to deleteAll
    deleteAll.id = 'deleteAll';
    //add a value to our deleteAll button
    deleteAll.innerText = "Detele  All";

    deleteAll.addEventListener("click", function(event){
      event.preventDefault();
      deleteAllTask(event);
    });

    //append the delete button to the newTask div
    taskListHolding.appendChild(deleteAll);

  }
  
};

//save task
var saveTask = function(){
	var taskInput = document.getElementById('newTask');
	var newTask = taskInput.value;

	//add new value to your array
	taskArray.push(newTask);
	updateTasks();
	taskInput.value='';
	console.log(taskArray);
	console.log('hello');
};


//delete task
var deleteTask = function(e){
			var taskNumber = e.target.parentElement.id; 	
  taskArray.splice(taskNumber, 1);
  updateTasks();
};

//delete all tasks
var deleteAllTask = function(){
  taskArray.splice(0, taskArray.length);
  updateTasks();
};

//init
var init = function(){
	//define "add" button
	var addButton = document.getElementById("addButton");
	
	//add event listener for click
	addButton.addEventListener('click', function(e){
		
		e.preventDefault();
		saveTask();
		
		
	});
};

window.onload = init();