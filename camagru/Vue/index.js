
window.onload = function(){
  var like = document.getElementsByClassName("like");

  var addLike = function() {
      var photo = this.getAttribute("data");
      var span = this;
      var http = new XMLHttpRequest();
      http.open("POST", "/Controleur/like.php", true);
      http.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
      http.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          var sign = span.innerHTML.substr(span.innerHTML.length - 1);
          var nb = span.innerHTML.substr(0, span.innerHTML.length - 1);
          if (this.responseText == 1)
            span.innerHTML = Number(nb)-1+" +";
          else
            span.innerHTML = Number(nb)+1+" -";

        }
        else if (this.readyState == 4)
          alert(this.responseText);
      };
      http.send("img="+encodeURIComponent(photo));
  };

  for (var i = 0; i < like.length; i++) {
      like[i].addEventListener('click', addLike, false);
  }

  var comment = document.getElementById("comm");
  document.getElementById("new_comm").onkeydown = function search(e) {
	  if (e.key === 'Enter') {
		  var new_comm = this.value;
		  photo = this.id;
		  var input = this;
      	  var http = new XMLHttpRequest();
		  http.open("POST", "/Controleur/new_comm.php", true);
		  http.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		  http.onreadystatechange = function() {
			  if (this.readyState == 4 && this.status == 200) {
		  			input.value = '';
					var http = new XMLHttpRequest();
					http.open("POST", "/Controleur/comm.php", true);
					http.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
					http.onreadystatechange = function() {
						if (this.readyState == 4 && this.status == 200) {
							comment.querySelector('span').innerHTML = "";
							old_comm = JSON.parse(this.responseText);
							old_comm.forEach(function(element){
								var i = 0;
								element.forEach(function(text){
									if (i == 0)
										comment.querySelector('span').innerHTML += text+" (";
									else if (i == 1)
										comment.querySelector('span').innerHTML += text+"): ";
									else
										comment.querySelector('span').innerHTML += text;
									i++;
								});
								comment.querySelector('span').innerHTML += "<br />";
							});
							comment.querySelector('input').id = photo;
							comment.classList.remove("hide");
  		  					comment.style.top = window.innerHeight/2 - comment.offsetHeight/2 + "px";
						}
					};

					http.send("img="+encodeURIComponent(photo));
			  }
			  else if (this.readyState == 4)
				  alert(this.responseText);
		  };

		  http.send("img="+encodeURIComponent(photo)+"&comm="+encodeURIComponent(new_comm));
	  }
  }

  function isDescendant(parent, child) {
     var node = child.parentNode;
     while (node != null) {
         if (node == parent) {
             return true;
         }
         node = node.parentNode;
     }
     return false;
  }
  document.onclick = function(e){
    if (!(e.target == comment || isDescendant(comment, e.target)))
      comment.classList.add("hide");

  }
  var comm = document.getElementsByClassName("comm");

  var addComment = function() {
      var photo = this.getAttribute("data");
      var http = new XMLHttpRequest();
      http.open("POST", "/Controleur/comm.php", true);
      http.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
      http.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          comment.querySelector('span').innerHTML = "";
			old_comm = JSON.parse(this.responseText);
			old_comm.forEach(function(element){
				var i = 0;
				element.forEach(function(text){
					if (i == 0)
						comment.querySelector('span').innerHTML += text+" (";
					else if (i == 1)
						comment.querySelector('span').innerHTML += text+"): ";
					else
						comment.querySelector('span').innerHTML += text;
					i++;
				});
				comment.querySelector('span').innerHTML += "<br />";
			});
			comment.querySelector('input').id = photo;
			comment.classList.remove("hide");
  		  comment.style.top = window.innerHeight/2 - comment.offsetHeight/2 + "px";
  		  comment.style.maxHeight = window.innerHeight * 0.6 + "px";
        }
      };
      
      http.send("img="+encodeURIComponent(photo));
  };

  for (var i = 0; i < comm.length; i++) {
      comm[i].addEventListener('click', addComment, false);
  }


  
     
}
