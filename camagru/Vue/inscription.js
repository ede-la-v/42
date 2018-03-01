
      window.onload = function(){



	  function findGetParameter(parameterName) {
		  var result = null,
		  tmp = [];
		  location.search
			  .substr(1)
			  .split("&")
			  .forEach(function (item) {
				  tmp = item.split("=");
				  if (tmp[0] === parameterName) result = decodeURIComponent(tmp[1]);
			  });
		  return result;
	  }

	  if ((value = findGetParameter('error')))
	{
		if (value == "pass1")
			alert("Les deux MDP sont differents");
		else if (value == "mail1")
			alert("Email non valide");
		else if (value == "pseudo1")
			alert("Pseudo deja utilise");
		else if (value == "pass2")
			alert("Le MDP doit contenir entre 8 et 20 caracteres");
		else if (value == "pass3")
			alert("Le MDP doit contenir au moins une majuscule");
		else if (value == "pass4")
			alert("Le MDP doit contenir au moins un chiffre");
		else if (value == "pseudo2")
			alert("Le pseudo doit contenir entre 6 et 20 caracteres");

	}
  }
