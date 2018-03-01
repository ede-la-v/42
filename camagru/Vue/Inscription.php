

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="../bootstrap/css/bootstrap.min.css" rel="stylesheet">
		<script src="inscription.js"></script>
		<title>Inscription</title>
	</head>


    <body>
		<div class="container">
            <?php include($_SERVER['DOCUMENT_ROOT']."/Vue/entete.php"); ?>
            
			
			
				<form method="post" action="/Controleur/Inscription.php" class="row text-center navbar-form navbar-center">
					<div class="input-group">
						<label for="pseudo">Pseudo :</label> <input type="text" name="pseudo" id="pseudo"  class="input-sm form-control" required /><br />
						<label for="pass">Mot de passe :</label> <input type="password" name="pass" id="pass" class="input-sm form-control" required /><br />
						<label for="vpass">Vérif. MDP :</label> <input type="password" name="vpass" id="vpass" class="input-sm form-control" required /><br />
						<label for="email">E-mail :</label> <input type="email" name="email" id="email" class="input-sm form-control" required /><br />
						<input type="submit" name="Inscription" value="Inscription" id='inscription_membre' class='btn btn-primary btn-sm' />
					</div>
				
				</form>
				
				<?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/footer.php'); ?>
			
		</div>
			
    </body>
</html>
