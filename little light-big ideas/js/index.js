var dark = false;

function randomQuote() 
{
 $.ajax({
      url: "http://api.forismatic.com/api/1.0/",
      jsonp: "jsonp",
      dataType: "jsonp",
      data: {
        method: "getQuote",
        lang: "en",
        format: "jsonp"
      },
      success: function(quote) {
        $('#quote').html('&ldquo;'+quote.quoteText+'&rdquo;')
        $('#author').html("-"+quote.quoteAuthor)
      }
    });
}

 function shift() 
 {
  if(dark ==true){

      $(".chain").toggleClass("chain-pull");
      //$(".chain").css
      $("body").css("background-color","black");
      dark==false;
     }

     else{
      $(".chain").toggleClass("chain-pull");
      $("body").css("background-color","#c3783f");
      dark==true;
     }
}

randomQuote();


//Click on the button to generate another random quote

$('#random').click(function() {  
    randomQuote();
    console.log;
    dark = !dark;
    shift();
    console.log(dark);
  });


/*$(function(){
  $("#random").click(function()
  {
 

  });
});*/