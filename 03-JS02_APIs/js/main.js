var city = '';
var state = '';
var APIKey = 'f3b40c0ec2b1ba6d';

//loadWeather
var loadWeather = function(response){
	console.log('load weather is running')
	
	//check if error in network - Their end
	if(response.response.error){
		alert(response.response.error.description);
		return;
	}

	var thisCity = response.current_observation.display_location.city;
	var temp = response.current_observation.temp_f;
	var weather = response.current_observation.weather;
	var icon = response.current_observation.icon_url;

	$('.temperature').text(temp);
	$('.weather').text(weather);
	$('.currentCity').val(thisCity);
	$('.weatherIcon').html('<img src="' + icon + '">');

};


//getWeather function
var getWeather = function(){
	//link to URL jason file
	var thisURL = 'http://api.wunderground.com/api/' + APIKey + '/conditions/q/' + state + '/' + city + '.json'
	//sends 
	$.ajax({
		url : thisURL,
		datatype : 'jsonp',
		success : function(response){
			loadWeather(response);
		}
	});
	//check if running
	console.log('get weather is running');
};




//setLocation function
var setLocation = function(){
	console.log("set loaction is running");
	//city
	city = $('.currentCity').val();
		if(city == '' || city == null){
			alert("You Need to list a city");
			return;
		}


	//state
	state = $('.currentState').val();
	console.log("city: " +city+ " ,state: " + state);
	getWeather();
};


//init

var init = function(){
	console.log("running");
	$('#submit').click(function(e){
		e.preventDefault();
		setLocation();	
	});

};


$( document ).ready(function(){
	
	init();
	
});

//$(____) = Selectors
//		 .function() = doing what with the selector