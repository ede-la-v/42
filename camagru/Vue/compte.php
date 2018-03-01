<?php
session_start();
if (!isset($_SESSION["id"]))
	header("Location: /index.php?error=log");
?>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="../bootstrap/css/bootstrap.min.css" rel="stylesheet">
        <title>Mon Compte</title>
	</head>

    <body>
		<div class="container">
            <?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/entete.php'); ?>
			
            <div class="text-center">
			<a href="change_user.php" class='btn btn-primary'>Modifier mes donnees</a>
			<a href="photo_user.php" class='btn btn-primary'>Voir mes photos</a>
            </div>
				
				
			
			<?php include ($_SERVER['DOCUMENT_ROOT'].'/Vue/footer.php'); ?>
            
			
		</div>
		
    </body>
</html>
