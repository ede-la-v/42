
	
	<?php
	
	$req1 = $bdd->prepare('INSERT INTO likes(id_membre, id_photo) VALUES(:id_user, :id_foto)');
	$req1->execute(array(
    'id_user' => $_SESSION["id"],
    'id_foto' => $_POST["img"]
    ));
		
	
	?>
