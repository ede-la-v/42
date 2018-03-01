
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
		if (value == "pass")
			alert("Mauvais MDP");
		else if (value == "pseudo")
			alert("Mauvais pseudo ou email non validé");
	}
  }
