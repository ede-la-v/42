
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
			if (value == "mail1")
				alert("Mail non valide");
			if (value == "pseudo1")
				alert("Deja utilise");
			if (value == "pseudo2")
				alert("Le pseudo doit compter entre 6 et 20 caracteres");
			if (value == "pass2")
				alert("Le MDP doit compter entre 8 et 20 caracteres");
			if (value == "pass3")
				alert("Une majuscule mini dans le MDP");
			if (value == "pass4")
				alert("Un chiffre mini dans le MDP");
			if (value == "pass1")
				alert("MDP errone");
		}
  }
